#include<bits/stdc++.h>

using namespace std;

/*
    3.1 Three in One:
    Describe how you could use a single array to implement three stacks
*/

// Solution:
// The first stack is stored from the beginning of the array
// elements are stored at index 0, 1, 2, ...
// Always keep track of the index of the top element
//
// The second stack is stored from the end of the array
// elements are stored at index N-1, N-2, N-3, ...
// Also keep track of the index of the top element
//
// The third stack is stored at 1/3 the size of the array
// The same way as the first stack
//
// It's important to prevent different stacks from colliding
// The first stack can't exceed 1/3 the size of the array, otherwise it'll corrupt the third stack
// The third and second stack also should never overlap.
// before adding any element to any of them we must check if the new index is not already taken by the other stack

template<typename T>
class ArrayStack
{
private:
    int N; // array size
    T* arr;
    int firstStackIndex;
    int secondStackIndex;
    int thirdStackIndex;
public:
    ArrayStack(int n = 1000)
    {
        N = n;
        arr = new T[N];
        firstStackIndex = 0;
        secondStackIndex = N / 3;
        thirdStackIndex = N - 1;
    }

    void push(int index, T item)
    {
        switch (index)
        {
            case 0:
                if (firstStackIndex >= N / 3)
                {
                    throw std::range_error("First stack is FULL!");
                }
                arr[firstStackIndex] = item;
                firstStackIndex++;
                break;
            case 1:
                if (secondStackIndex >= thirdStackIndex)
                {
                    throw std::range_error("Second stack is FULL!");;
                }
                arr[secondStackIndex] = item;
                secondStackIndex++;
                break;
            case 2:
                if (secondStackIndex >= thirdStackIndex)
                {
                    throw std::range_error("Third stack is FULL!");
                    return;
                }
                arr[thirdStackIndex] = item;
                thirdStackIndex--;
                break;

            default:
                throw std::invalid_argument::invalid_argument();
                break;
        }

    }

    T pop(int index)
    {
        switch (index)
        {
            case 0:
                if (firstStackIndex <= 0)
                {
                    throw std::out_of_range("First stack is empty!");
                }
                firstStackIndex--;
                return arr[firstStackIndex];

            case 1:
                if (secondStackIndex <= N / 3)
                {
                    throw std::out_of_range("Second stack is empty!");
                }
                secondStackIndex--;
                return arr[secondStackIndex];

            case 2:
                if (thirdStackIndex >= N - 1)
                {
                    throw std::out_of_range("Third stack is empty!");
                }
                thirdStackIndex++;
                return arr[thirdStackIndex];

            default:
                throw std::invalid_argument::invalid_argument();
                break;
        }
    }


    bool isEmpty(int index)
    {
        switch (index)
        {
            case 0:
                return firstStackIndex <= 0;
            case 1:
                return secondStackIndex <= N / 3;
            case 2:
                return thirdStackIndex >= N - 1;
            default:
                throw std::invalid_argument::invalid_argument();
                break;
        }
        return 0;
    }

    void displayContent()
    {
        cout << "First stack content";
        for (int i = 0; i < firstStackIndex; i++)
        {
            cout << " " << arr[i];
        }
        cout << endl;

        cout << "Second stack content";
        for (int i = N / 3; i < secondStackIndex; i++)
        {
            cout << " " << arr[i];
        }
        cout << endl;

        cout << "Third stack content";
        for (int i = N - 1; i > thirdStackIndex; i--)
        {
            cout << " " << arr[i];
        }
        cout << endl;
        cout << "----------------------------------------------" << endl;
    }

};

int main()
{
    ArrayStack<int> arrayStack = ArrayStack<int>();
    for (int curStack = 0; curStack < 3; curStack++)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "Push " << i * (curStack + 1) << " to stack #" << curStack << endl;
            arrayStack.push(curStack, i * (curStack + 1));
        }
        cout << "----------------------------------------------" << endl;
    }

    arrayStack.displayContent();

    for (int curStack = 0; curStack < 3; curStack++)
    {
        while (!arrayStack.isEmpty(curStack))
        {
            cout << "Pop " << arrayStack.pop(curStack) << " from stack #" << curStack << endl;
        }
        cout << "----------------------------------------------" << endl;
    }

    return 0;
}
