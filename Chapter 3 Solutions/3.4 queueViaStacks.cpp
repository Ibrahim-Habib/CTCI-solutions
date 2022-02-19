#include<bits/stdc++.h>

using namespace std;

/*
    3.4 Queue via Stacks:
    Implement a MyQueue class which implements a queue using two stacks.

*/

// Solution:
// To enqueue push the value into the first stack
// To dequeue move all the content from the first to the second stack then pop the top of the second
// Time Complexity: push O(n), pop O(n)
// While it has linear complexity in worst case.
// If pops and pushes are not alternating then the actual steps would be much less than N for each operation


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

    void push(int item)
    {
        if (stackSize >= capacity)
        {
            throw std::range_error("Stack is FULL!!");
        }
        arr[stackSize] = item;
        stackSize++;
    }

    int pop()
    {
        if (isEmpty())
        {
            throw std::invalid_argument("Stack is empty!!");
        }

        stackSize--;
        return arr[stackSize];
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
class MyQueue
{
private:
    int singleStackCapacity;
    ArrayStack<T> stack1, stack2;
public:
    MyQueue()
    {
        stack1 = ArrayStack<T>();
        stack2 = ArrayStack<T>();
    }

    void enqueue(T item)
    {
        while (!stack2.isEmpty())
        {
            stack1.push(stack2.pop());
        }
        stack1.push(item);
    }

    T dequeue()
    {
        while (!stack1.isEmpty())
        {
            stack2.push(stack1.pop());
        }
        return stack2.pop();
    }

    bool isEmpty()
    {
        return stack1.isEmpty() && stack2.isEmpty();
    }

    void displayContent()
    {
        while (!stack2.isEmpty())
        {
            stack1.push(stack2.pop());
        }
        stack1.displayContent();
    }
};

int main()
{
    MyQueue<int>myqueue = MyQueue<int>();
    // STL queue (for testing)
    queue<int>q;
    srand(time(0));
    for (int i = 0; i < 30; i++)
    {
        int op = rand() % 6;
        if (!myqueue.isEmpty() && op < 2)
        {
            int val = myqueue.dequeue();
            cout << "Dequeue " << val << endl;
            // test myqueue against STL's queue
            assert(val == q.front());
            q.pop();
        }
        else
        {
            int num = rand() % 50;
            cout << "Enqueue " << num << endl;
            myqueue.enqueue(num);
            q.push(num);
        }
    }

    cout << "My queue's content:" << endl;
    myqueue.displayContent();
    cout << "STL's queue's content:" << endl;
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
