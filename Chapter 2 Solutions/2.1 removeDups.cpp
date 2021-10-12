#include<bits/stdc++.h>

using namespace std;

/*
    2.1 remove Dups:
    Write code to remove duplicates from an unsorted linked list.
    FOLLOW UP
    How would you solve this problem if a temporary buffer is not allowed_
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


// Naive solution:
// for each Node remove all nodes with the same value after it
// Time Complexity O(N^2)
// Memory Complexity O(1)
Node* removeDupsNaive(Node* head)
{
    Node* cur = head;
    while(cur)
    {
        Node* tmp = cur;
        while(tmp)
        {
            while(tmp->next && tmp->next->val == cur->val)
            {
                Node* toDelete = tmp->next;
                tmp->next = tmp->next->next;
                delete toDelete;
            }
            tmp = tmp->next;
        }
        cur = cur->next;
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
    Node* n = createLinkedList(10, 1, 7);
    displayLinkedList(n);
    Node* nUnique = removeDupsNaive(n);
    displayLinkedList(nUnique);
    return 0;
}
