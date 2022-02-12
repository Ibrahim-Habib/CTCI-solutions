#include<bits/stdc++.h>

using namespace std;

/*
    3.3 Stack of Plates:
    Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
    Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.
    Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks
    and should create a new stack once the previous one exceeds capacity.
    SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack
    (that is, pop() should return the same values as it would if there were just a single stack).

    FOLLOW UP
    Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
*/

// Solution:
// Create a vector of stacks. Then always operate on the last stack in the vector

// Note: The follow up is not implemented


class ArrayStack
{
private:
    int capacity; // array size
    int* arr;
    int stackSize;
public:
    ArrayStack(int n = 1000)
    {
        capacity = n;
        arr = new int[n];
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

class SetOfStacks
{
private:
    int singleStackCapacity;
    vector<ArrayStack>stacks;
public:
    SetOfStacks(int stackCapacity = 10)
    {
        stacks.push_back(ArrayStack(stackCapacity));
        singleStackCapacity = stackCapacity;
    }

    void push(int item)
    {
        if (stacks.back().isFull())
        {
            stacks.push_back(ArrayStack(singleStackCapacity));
        }
        stacks[stacks.size() - 1].push(item);
    }

    int pop()
    {
        int returnValue = stacks[stacks.size() - 1].pop();
        if (stacks.size() > 1 && stacks.back().isEmpty())
        {
            stacks.pop_back();
        }
        return returnValue;
    }

    bool isEmpty()
    {
        return stacks.size() <= 1 && stacks[0].isEmpty();
    }

    void displayContent()
    {
        cout << "Stack's Content :" << endl;;
        for (int i = 0; i < stacks.size(); i++)
        {
            stacks[i].displayContent();
        }
    }
};

int main()
{
    SetOfStacks arrayStack = SetOfStacks();
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        int op = rand() % 6;
        if (!arrayStack.isEmpty() && op < 2)
        {
            cout << "Pop " << arrayStack.pop() << endl;
        }
        else if(op == 2)
        {
            arrayStack.displayContent();
        }
        else
        {
            int num = rand() % 50;
            cout << "Push " << num << endl;
            arrayStack.push(num);
        }
    }

    return 0;
}
