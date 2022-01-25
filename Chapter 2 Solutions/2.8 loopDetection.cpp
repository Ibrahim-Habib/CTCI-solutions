#include<bits/stdc++.h>

using namespace std;

/*
    2.8 Loop Detection:
    Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop

    DEFINITION
    Circular linked list: A (corrupt) linked list in which a node's next pointer
    points to an earlier node, so as to make a loop in the linked list.

    EXAMPLE
    Input: A -> B -> C -> D -> E -> C(the same C as earlier)
    Output: C

*/

// Node struct
struct Node{
    int val;
    Node* next;
    Node(int v)
    {
        val = v;
        next = NULL;
    }
};

Node* createLinkedList(int , int , int );
Node* getTail(Node*);

// Solution:
// First detect the loop (by a fast and a slow pointer)
// then trying for each node inside the loop to cut the link
// between it and the next and moving another pointer from the head
// if that pointer reached the next first then the next is the beginning of the loop
// Time Complexity O(NM)
//      where N is the list length
//      and M is the loop length
// Memory Complexity O(1)
Node* detectLoop(Node* head)
{
    Node* fastNode, *slowNode, *nodeInTheLoop;
    nodeInTheLoop = NULL;
    fastNode = slowNode = head;
    while (fastNode != NULL)
    {
        fastNode = fastNode->next;
        slowNode = slowNode->next;

        if (fastNode != NULL)
        {
            fastNode = fastNode->next;
        }
        else
        {
            // not a circular linked list
            return NULL;
        }

        if (fastNode == slowNode)
        {
            nodeInTheLoop = fastNode;
            break;
        }
    }

    if (nodeInTheLoop == NULL)
    {
        return NULL;
    }

    while (1)
    {
        // cut the link to the next
        Node* nxt = nodeInTheLoop->next;
        nodeInTheLoop->next = NULL;
        //start moving tmp from the head
        Node* tmp = head;
        while(tmp != nodeInTheLoop)
        {
            if (tmp == nxt)
            {
                return tmp;
            }
            tmp = tmp->next;
        }

        // return the link to the next
        nodeInTheLoop->next = nxt;
        nodeInTheLoop = nodeInTheLoop->next;
    }

    return NULL;
}

// helper functions
Node* createLinkedList(int length, int minVal, int maxVal)
{
    Node* head;
    Node* cur;
    head = cur = NULL;
    for(int i = 0; i < length; i++)
    {
        int val = minVal + rand() % (maxVal - minVal + 1);
        if(head == NULL)
        {
            cur = new Node(val);
            head = cur;
        }
        else
        {
            Node* tmp = new Node(val);
            cur->next = tmp;
            cur = cur->next;
        }
    }

    return head;
}

Node* getTail(Node* n)
{
    while(n->next != NULL)
    {
        n = n->next;
    }
    return n;
}

void displayLinkedList(Node* n)
{
    while(n)
    {
        cout << n->val;
        if(n->next != NULL)
        {
            cout << " -> ";
        }
        else
        {
            cout << endl;
        }
        n = n->next;
    }
}


int main()
{
    int len = 5;
    srand(time(0));
    Node* head1 = createLinkedList(4, 0, 9);
    Node* res = detectLoop(head1);
    assert(res == NULL);
    delete head1;
    head1 = createLinkedList(20, 0, 100);
    Node* tail = getTail(head1);
    // display the list before corruption
    displayLinkedList(head1);
    // corrupt the list, make a loop which starts from the 3rd node
    tail->next = head1->next->next;
    res = detectLoop(head1);
    cout << "The loop starts with the node whose value = " << res->val << " and next = " << res->next->val << endl;

    delete head1;
    head1 = createLinkedList(30, 0, 100);
    tail = getTail(head1);
    // display the list before corruption
    displayLinkedList(head1);
    // corrupt the list, make a loop which starts from the head
    tail->next = head1;
    res = detectLoop(head1);
    cout << "The loop starts with the node whose value = " << res->val << " and next = " << res->next->val << endl;

    return 0;
}
