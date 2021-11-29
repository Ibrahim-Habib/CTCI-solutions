#include<bits/stdc++.h>

using namespace std;

/*
    2.3 Delete middle node:
    Implement an algorithm to delete a node in the middle
    (i.e., any node but the first and last node, not necessarily the exact middle)
    of a singly linked list, given only access to that node
    EXAMPLE:
    Input: the node c from the linked list a->b->c->d->e->f
    Result: nothing is returned, but the new linked list looks like a->b->d->e->f
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


// Solution:
// Iterate from the head until the node to be deleted becomes the next node
// then make the next of the current node points to the next of the next node (the node to be deleted)
// now the list is updated
// we should delete also the node itself from memory (to avoid memory leaks)
// Time Complexity O(N)
// Memory Complexity O(1)
void deleteMiddleNode(Node* head, Node* nodeToDelete)
{
    Node* cur = head;
    while(cur && cur->next != nodeToDelete)
    {
        cur = cur->next;
    }
    cur->next = cur->next->next;
    delete nodeToDelete;
}

// helper functions
Node* createLinkedList(int length, int minVal, int maxVal)
{
    Node* head;
    Node* cur;
    head = cur = NULL;
    for(int i = 0; i < length; i++)
    {
        int val = minVal + rand() % (maxVal - minVal);
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
    int len = 10;
    srand(time(0));
    Node* head = createLinkedList(len, 1, 30);
    int randomIndex = 1 + rand() % (len - 2);
    Node* nodeToDelete = head;
    for (int i = 0; i < randomIndex; i++)
    {
        nodeToDelete = nodeToDelete->next;
    }
    cout << "List Before:" << endl;
    displayLinkedList(head);
    cout << "Delete Node at index " << randomIndex << " with value = " << nodeToDelete->val << endl;
    deleteMiddleNode(head, nodeToDelete);
    cout << "List After:" << endl;
    displayLinkedList(head);
    return 0;
}
