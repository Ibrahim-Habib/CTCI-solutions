#include<bits/stdc++.h>

using namespace std;

/*
    2.4 Partition:
    Write code to partition a linked list around a value x,
    such that all nodes less than x come before all nodes greater than or equal to x.
    If x is contained within the list, the values of x only need to be after the elements less than x (see below).
    The partition element x can appear anywhere in the "right partition";
    It does not need to appear between the left and the right partition.
    EXAMPLE:
    Input:      3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
    Output:     3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
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
// Iterate from the head until the tail while keeping a pointer to the head
// when a value less than x is found we make it the new head and remove it form the list.
// Time Complexity O(N)
// Memory Complexity O(1)
Node* partitionList(Node* head, int x)
{
    Node* cur = head;
    while(cur->next)
    {
        if (cur->next->val < x)
        {
            Node* tmp = cur->next;
            cur->next = cur->next->next;
            tmp->next = head;
            head = tmp;
        }
        else
        {
            cur = cur->next;
        }
    }
    return head;
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
    Node* head = createLinkedList(len, 1, 5);
    //int partitionValue = 1 + rand() % 10;
    int partitionValue = 3;
    Node* nodeToDelete = head;
    cout << "List Before:" << endl;
    displayLinkedList(head);
    cout << "Partition Value = " << partitionValue << endl;
    head = partitionList(head, partitionValue);
    cout << "List After:" << endl;
    displayLinkedList(head);
    return 0;
}
