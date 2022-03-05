#include<bits/stdc++.h>

using namespace std;

/*
    3.5 Sort Stack:
    Write a program to sort a stack such that the smallest items are on the top.
    You can use an additional temporary stack, but you may not copy the elements into any other data structure
    (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.

*/

// Solution:
// By having the stack sorted such that the top element is the smallest.
// and having an additional temporary stack.
// When inserting an item into our main stack, We pop until the top item is greater than the inserted item.
// After inserting the new item we push items back to the main stack.

template<typename T>
class ArrayStack
{
private:
    int capacity; // array size
    T* arr;
    int stackSize;
public:
    ArrayStack(int n = 1000)
    {
        capacity = n;
        arr = new T[n];
        stackSize = 0;
    }

    void push(T item)
    {
        if (stackSize >= capacity)
        {
            throw std::range_error("Stack is FULL!!");
        }
        arr[stackSize] = item;
        stackSize++;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::invalid_argument("Stack is empty!!");
        }

        stackSize--;
        return arr[stackSize];
    }

    T top()
    {
        if (isEmpty())
        {
            throw std::invalid_argument("Stack is empty!!");
        }

        return arr[stackSize - 1];
    }

    bool isEmpty()
    {
        return stackSize <= 0;
    }

    bool isFull()
    {
        return stackSize >= capacity;
    }

    void displayContent()
    {
        for (int i = 0; i < stackSize; i++)
        {
            cout << " " << arr[i];
        }
        cout << endl;
    }
};

template<typename T>
class SortedStack
{
private:
    int singleStackCapacity;
    ArrayStack<T> mainStack, tempStack;
public:
    SortedStack()
    {
        mainStack = ArrayStack<T>();
        tempStack = ArrayStack<T>();
    }

    void push(T item)
    {
        while (!tempStack.isEmpty() && tempStack.top() > item)
        {
            mainStack.push(tempStack.pop());
        }

        while (!mainStack.isEmpty() && mainStack.top() < item)
        {
            tempStack.push(mainStack.pop());
        }

        mainStack.push(item);
    }

    T pop()
    {
        while (!tempStack.isEmpty())
        {
            mainStack.push(tempStack.pop());
        }
        return mainStack.pop();
    }

    bool isEmpty()
    {
        return mainStack.isEmpty() && tempStack.isEmpty();
    }

    void displayContent()
    {
        while (!tempStack.isEmpty())
        {
            mainStack.push(tempStack.pop());
        }
        mainStack.displayContent();
    }
};

int main()
{
    SortedStack<int> sortedStack = SortedStack<int>();
    srand(time(0));
    for (int i = 0; i < 40; i++)
    {
        int op = rand() % 7;
        if (!sortedStack.isEmpty() && op < 2)
        {
            int val = sortedStack.pop();
            cout << "Pop " << val << endl;
        }
        else
        {
            int num = rand() % 100;
            cout << "Push " << num << endl;
            sortedStack.push(num);
        }
    }

    cout << "My sorted stack's content:" << endl;
    sortedStack.displayContent();

    return 0;
}
