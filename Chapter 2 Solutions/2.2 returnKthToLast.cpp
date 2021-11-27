#include<bits/stdc++.h>

using namespace std;

/*
    2.1 return Kth to last:
    Implement an algorithm to find the kth to last element of a singly linked list
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
// find the length of the list, then traverse the list again
// to the node n - k
// Time Complexity O(N)
// Memory Complexity O(1)
Node* getKthToLastNaive(Node* head, int k)
{
    Node* cur = head;
    int listLength = 0;
    while (cur)
    {
        listLength++;
        cur = cur->next;
    }

    cur = head;

    for (int i = 0; i < listLength - k; i++)
    {
        cur = cur->next;
    }
    return cur;
}

// Better solution:
// advance a pointer by k elements from the head
// then move it simultaneously with another pointer which points to the head
// when the second node reaches to the end of the list, the first node is on the kth to last element
// it's better than the naive solution in that it only traverses the list once (better constant factor)
// Time Complexity O(N)
// Memory Complexity O(1)
Node* getKthToLastOptimized(Node* head, int k)
{
    Node* advancedPtr = head;
    for (int i = 0; advancedPtr != NULL && i < k; i++)
    {
        advancedPtr = advancedPtr->next;
    }

    Node* behindPtr = head;

    while(advancedPtr)
    {
        advancedPtr = advancedPtr->next;
        behindPtr = behindPtr->next;
    }
    return behindPtr;
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
    int len = 20;
    Node* n = createLinkedList(len, 1, 20);
    displayLinkedList(n);
    Node* lastNode = getKthToLastNaive(n, 1);
    Node* secondToLastNode = getKthToLastNaive(n, 2);
    Node* firstNode = getKthToLastNaive(n, len);
    Node* secondNode = getKthToLastNaive(n, len - 1);
    displayLinkedList(n);
    cout << "Naive Solution:" << endl;
    cout << firstNode->val << " " << secondNode->val << " " << secondToLastNode->val << " " << lastNode->val << endl;

    Node* last = getKthToLastOptimized(n, 1);
    Node* secondToLast= getKthToLastOptimized(n, 2);
    Node* firstN = getKthToLastOptimized(n, len);
    Node* secondN= getKthToLastOptimized(n, len - 1);
    cout << "Optimized Solution:" << endl;
    cout << firstN->val << " " << secondN->val << " " << secondToLast->val << " " << last->val << endl;
    return 0;
}
