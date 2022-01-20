#include<bits/stdc++.h>

using namespace std;

/*
    2.6 Palindrome:
    Implement a function to check if a linked list is a palindrome.
*/

// Node struct
struct Node{
    char val;
    Node* next;
    Node(char v)
    {
        val = v;
        next = NULL;
    }
};

Node* createLinkedList(int , int , int );


// Solution:
// Reverse the second half of the list
// then traverse the list from the beginning and the end
// Make sure to return the list to the original state
bool isPalindrome(Node* head)
{
    // create 2 nodes that will move with different speeds
    // at the end slowNode will point to the middle node
    Node* slowNode, *fastNode;
    slowNode = fastNode = head;
    while (fastNode->next != NULL)
    {
        fastNode = fastNode->next;
        if (fastNode->next != NULL)
        {
            slowNode = slowNode->next;
            fastNode = fastNode->next;
        }
    }

    // reversing the second half of the list
    Node* curNode, * prevNode, *nextNode;
    prevNode = slowNode;
    if (prevNode != NULL)
        curNode = slowNode->next;
    if (curNode != NULL)
        nextNode = curNode->next;

    while (curNode != NULL)
    {
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
        if (curNode != NULL)
            nextNode = curNode->next;
    }

    // checking the first half and the reversed second half
    Node* forwardNode = head;
    Node* backwardNode = prevNode;
    Node* prevForward = NULL;
    bool res = true;
    while (forwardNode != backwardNode && backwardNode != prevForward)
    {
        if (forwardNode->val != backwardNode->val)
        {
            res = false;
            break;
        }
        prevForward = forwardNode;
        forwardNode = forwardNode->next;
        backwardNode = backwardNode->next;
    }

    // reverse the second half again (to restore the state of the original list)
    curNode = prevNode->next;
    prevNode->next = NULL;
    if (curNode != NULL)
        nextNode = curNode->next;

    while(curNode != NULL && curNode != slowNode)
    {
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
        nextNode = curNode->next;
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
    Node* head1 = createLinkedList(1, 'a', 'z');
    cout << "list before:" << endl;
    displayLinkedList(head1);
    cout << "is Palidrome: ";
    if (isPalindrome(head1))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    cout << "list after:" << endl;
    displayLinkedList(head1);

    cout << "----------------------------------------------" << endl;
    delete head1;

    Node* head2 = createLinkedList(2, 'c', 'c');
    cout << "list before:" << endl;
    displayLinkedList(head2);
    cout << "is Palidrome: ";
    if (isPalindrome(head2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    cout << "list after:" << endl;
    displayLinkedList(head2);
    cout << "----------------------------------------------" << endl;
    delete head2;

    head2 = createLinkedList(3, 'a', 'j');
    cout << "list before:" << endl;
    displayLinkedList(head2);
    cout << "is Palidrome: ";
    if (isPalindrome(head2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    cout << "list after:" << endl;
    displayLinkedList(head2);
    cout << "----------------------------------------------" << endl;


    while(!isPalindrome(head2))
    {
        delete head2;
        int len = 3 + rand() % 8;
        // reduce the characters to only 10 characters
        // to increase the palindrome chance
        head2 = createLinkedList(len, 'a', 'j');
        cout << "list before:" << endl;
        displayLinkedList(head2);
        cout << "is Palidrome: ";
        if (isPalindrome(head2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        cout << "list after:" << endl;
        displayLinkedList(head2);
        cout << "----------------------------------------------" << endl;
    }

    return 0;
}
