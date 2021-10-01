#include<bits/stdc++.h>

using namespace std;

/// NOT TESTED YET

/*
    Is Unique:
    Implement an algorithm to determine if a string has all unique characters.
    What if you cannot use additional data structures?
*/

// Brute force solution, O(N^2)
bool isUniqueBruteforce(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = i + 1; j < s.size(); j++)
        {
            if(s[i] == s[j])
            {
                return false;
            }
        }
    }

    return true;
}

// No extra Data Structures solution, O(N log(N))
bool isUniqueSorting(string s)
{
    sort(s.begin(), s.end());
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i - 1])
        {
            return false;
        }
    }

    return true;
}

// Solution using Counting map, O(N)
/*
    map is used instead of an array because
    char (which is used as an index) may be negative.
*/
bool isUniqueLinear(string s)
{
    map<char, int> charCount;
    for(int i = 0; i < s.size(); i++)
    {
        charCount[s[i]]++;
        if(charCount[s[i]] > 1)
        {
            return false;
        }
    }

    return true;
}
