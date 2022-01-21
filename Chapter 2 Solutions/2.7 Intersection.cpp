#include<bits/stdc++.h>

using namespace std;

/*
    2.7 Intersection:
    Given two (singly) linked lists, determine if the two lists intersect.
    Return the intersecting node.
    Note that the intersection is defined based on reference, not value.
    That is, if the kth node of the first linked list is the exact same node (by reference)
    as the jth node of the second linked list, then they are intersecting.
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
// First let's get the tail nodes of the two lists.
// If the tails are different then they don't intersect
// If the tails are the same then we start again from the head
// We move the pointer of the longest list by the length difference
// then we move both pointers simultaneously until the two references are the same
Node* Intersection(Node* head1, Node* head2)
{
    Node* tail1 = getTail(head1);
    Node* tail2 = getTail(head2);
    if (tail1 != tail2)
    {
        // They don't intersect
        return NULL;
    }

    Node* n1 = head1;
    Node* n2 = head2;
    while (n1->next != NULL && n2->next != NULL)
    {
        n1 = n1->next;
        n2 = n2->next;
    }

    int difference = 0;
    // if the first list is longer than the second
    while(n1->next != NULL)
    {
        difference++;
        n1 = n1->next;
    }

    // if the second list is longer than the first
    while (n2->next != NULL)
    {
        difference--;
        n2 = n2->next;
    }

    n1 = head1;
    n2 = head2;
    while (difference > 0)
    {
        n1 = n1->next;
        difference--;
    }

    while (difference < 0)
    {
        n2 = n2->next;
        difference++;
    }

    while(n1 != n2)
    {
        n1 = n1->next;
        n2 = n2->next;
    }

    return n1;
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

void displayRes(Node* n)
{
    if (n == NULL)
    {
        cout << "The lists doesn't intersect" << endl;
    }
    else
    {
        cout << "The lists intersection is :";
        displayLinkedList(n);
    }
}

int main()
{
    int len = 5;
    srand(time(0));
    // 1 item list (different)
    Node* head1 = createLinkedList(1, 0, 9);
    Node* head2 = createLinkedList(1, 0, 9);
    Node* res = Intersection(head1, head2);
    displayRes(res);
    delete head1;

    head1 = createLinkedList(1, 0, 9);
    head2 = head1;
    res = Intersection(head1, head2);
    displayRes(res);
    delete head1;
    delete head2;

    head1 = createLinkedList(5, 0, 10);
    head2 = createLinkedList(5, 0, 10);
    res = Intersection(head1, head2);
    displayRes(res);
    delete head1;
    delete head2;

    head1 = createLinkedList(5, 0, 10);
    head2 = createLinkedList(5, 0, 10);
    Node* tail1 = getTail(head1);
    Node* tail2 = getTail(head2);
    Node* head3 = createLinkedList(3, 0, 10);
    tail1->next = head3;
    tail2->next = head3;
    res = Intersection(head1, head2);
    displayRes(res);
    delete head1;
    delete head2;

    head1 = createLinkedList(2, 0, 10);
    head2 = createLinkedList(7, 0, 10);
    tail1 = getTail(head1);
    tail2 = getTail(head2);
    head3 = createLinkedList(5, 0, 10);
    tail1->next = head3;
    tail2->next = head3;
    res = Intersection(head1, head2);
    displayRes(res);
    delete head1;
    delete head2;

    head1 = createLinkedList(5, 0, 10);
    head2 = createLinkedList(3, 0, 10);
    tail1 = getTail(head1);
    tail2 = getTail(head2);
    head3 = createLinkedList(1, 0, 10);
    tail1->next = head3;
    tail2->next = head3;
    res = Intersection(head1, head2);
    displayRes(res);
    delete head1;
    delete head2;

    head1 = createLinkedList(10, 0, 10);
    head2 = createLinkedList(9, 0, 10);
    res = Intersection(head1, head2);
    displayRes(res);
    delete head1;
    delete head2;

    return 0;
}
