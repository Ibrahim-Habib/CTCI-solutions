#include<bits/stdc++.h>

using namespace std;

/// TESTED BY geeksforgeeks.com
/// https://practice.geeksforgeeks.org/problems/anagram-1587115620/1#

/*
    1.2 Check Permutation:
    Given two strings, write a method to decide if one is a permutation of the other.
*/


// Sorting both, O(N1 log(N1) + N2 log(N2))
bool checkPermutationSorting(string s1, string s2)
{
    if(s1.size() != s2.size())
    {
        return false;
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

// Solution using Counting array, O(N)
// assuming that characters of both strings are alphanumeric
bool checkPermutationCounting(string s1, string s2)
{
    if(s1.size() != s2.size())
    {
        return false;
    }

    int c[255];

    //initialization of counting array by zeros
    for(int i = 0; i < 255; i++)
    {
        c[i] = 0;
    }

    for(int i = 0; i < s1.size(); i++)
    {
        c[s1[i]]++;
    }

    for(int i = 0; i < s2.size(); i++)
    {
        c[s2[i]]--;
        if(c[s2[i]] < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s1 = "door";
    string s1Anagram = "doro";
    string s1NotAnagram = "road";

    assert(checkPermutationCounting(s1, s1Anagram));
    assert(checkPermutationSorting(s1, s1Anagram));

    assert(!checkPermutationCounting(s1, s1NotAnagram));
    assert(!checkPermutationSorting(s1, s1NotAnagram));

    return 0;
}
