#include<bits/stdc++.h>

using namespace std;

/*
    1.3 URLify:
    Write a method to replace all spaces in a string with '%20'.
    You may assume that the string has sufficient space at the end to hold the additional characters,
    and that you are given the `true` length of the string.
    (Note: If implemented in Java, please use a character array so that you can perform this operation in place.)
*/

// in place solution.
// Time complexity: O(N)
// Note: This solution assumes that the length of the string
// is length + 2 * spaces count
// so no extra space exists
string URLify(string s, int length)
{
    int secondIndex;
    int firstIndex;
    secondIndex = s.size() - 1;
    firstIndex = length - 1;
    while(firstIndex != secondIndex && firstIndex >= 0)
    {
        if(s[firstIndex] == ' ')
        {
            s[secondIndex] = '0';
            secondIndex--;
            s[secondIndex] = '2';
            secondIndex--;
            s[secondIndex] = '%';
            secondIndex--;
        }
        else
        {
            s[secondIndex] = s[firstIndex];
            secondIndex--;
        }
        firstIndex--;
    }

    return s;
}
