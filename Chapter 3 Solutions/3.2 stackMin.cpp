#include<bits/stdc++.h>

using namespace std;

/*
    3.2 Stack Min:
    How would you design a stack which, in addition to push and pop,
    has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time.
*/

// Solution:
// Every stack element will hold the min value so far, in addition to its value
// So to get the min we can always access it from the top element

class ArrayStack
{
private:
    int N; // array capacity
    int* arr;
    int* minSoFar;
    int stackSize;
public:
    ArrayStack(int n = 1000)
    {
        N = n;
        arr = new int[N];
        minSoFar = new int[N];
        stackSize = 0;
    }

    void push(int item)
    {
        if (stackSize == N)
        {
            throw std::range_error("Stack is FULL!!");
        }
        arr[stackSize] = item;
        if (stackSize == 0)
        {
            minSoFar[stackSize] = item;
        }
        else
        {
            minSoFar[stackSize] = min(item, minSoFar[stackSize - 1]);
        }

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

    int getMin()
    {
        if (isEmpty())
        {
            throw std::invalid_argument("Stack is empty!!");
        }

        return minSoFar[stackSize - 1];
    }

    bool isEmpty()
    {
        return stackSize <= 0;
    }

    void displayContent()
    {
        cout << "stack content";
        for (int i = 0; i < stackSize; i++)
        {
            cout << " " << arr[i];
        }
        cout << endl;
    }

};

int main()
{
    ArrayStack arrayStack = ArrayStack();
    srand(time(0));
    for (int i = 0; i < 30; i++)
    {
        int op = rand() % 7;
        if (!arrayStack.isEmpty() && op == 0)
        {
            cout << "------------------------------------------" << endl;
            arrayStack.displayContent();
            cout << "min value in stack = " << arrayStack.getMin() << endl;
            cout << "------------------------------------------" << endl;
        }
        if (!arrayStack.isEmpty() && op <= 3)
        {
            cout << "pop " << arrayStack.pop() << endl;
        }
        else
        {
            int val = rand() % 100;
            cout << "push " << val << endl;
            arrayStack.push(val);
        }
    }

    return 0;
}
