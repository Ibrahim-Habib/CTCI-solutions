#include<bits/stdc++.h>

using namespace std;

/*
    2.5 Sum Lists:
    You have two numbers represented by a linked list, where each node contains a single digit.
    The digits are stored in reverse order, such that the 1's digit is at the head of the list.
    Write function that adds the two numbers and returns the sum as a linked list.
    EXAMPLE
    Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
    Output: 2 -> 1 -> 9. That is, 912.

    FOLLOW UP
    Suppose the digits are stored in forward order. Repeat the above problem.
    EXAMPLE
    Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295
    Output: 9 -> 1 -> 2. That is, 912.
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
// Simply by summing values while keeping the carry at each digit
// Time Complexity O(N)
// Memory Complexity O(1)
Node* sumList(Node* head1, Node* head2)
{
    Node* res = NULL;
    Node* curRes = NULL;

    Node* cur1 = head1;
    Node* cur2 = head2;

    int carry = 0;
    while (cur1 != NULL || cur2 != NULL || carry > 0)
    {
        if (curRes == NULL)
        {
            curRes = new Node(0);
            res = curRes;
        }
        else
        {
            curRes->next = new Node(0);
            curRes = curRes->next;
        }

        if (cur1 != NULL && cur2 != NULL)
        {
            curRes->val = (cur1->val + cur2->val + carry) % 10;
            carry = (cur1->val + cur2->val + carry) / 10;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        else if (cur1 != NULL)
        {
            curRes->val = (cur1->val + carry) % 10;
            carry = (cur1->val + carry) / 10;
            cur1 = cur1->next;
        }
        else if (cur2 != NULL)
        {
            curRes->val = (cur2->val + carry) % 10;
            carry = (cur2->val + carry) / 10;
            cur2 = cur2->next;
        }
        else if (carry > 0)
        {
            curRes->val = carry % 10;
            carry /= 10;
        }
    }
    return res;
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
    int len = 5;
    srand(time(0));
    Node* head1 = createLinkedList(4, 0, 9);
    Node* head2 = createLinkedList(4, 0, 9);
    cout << "First List: ";
    displayLinkedList(head1);
    cout << "Second List: ";
    displayLinkedList(head2);
    Node* sum = sumList(head1, head2);
    cout << "Sum List: ";
    displayLinkedList(sum);
    return 0;
}
