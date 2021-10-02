#include<bits/stdc++.h>

using namespace std;

/*
    1.5 One Away:
    There are three types of edits that can be performed on strings:
    insert a character, remove a character, or replace a character.
    Given two strings, write a function to check if they are one edit (or zero edits) away.
    EXAMPLE
    pale, ple -> true
    pales, pale -> true
    pale, bale -> true
    pale, bake -> false
*/

// Assuming that changes are made to the first string
// O(N) where N is the length of the first string
bool isOneAway(string s1, string s2)
{
    if(s1.size() == s2.size()) //check for replace or identical strings
    {
        int diffCount = 0;
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i])
            {
                diffCount++;
            }
        }

        return diffCount <= 1;
    }
    else if(s1.size() == s2.size() + 1) // check for a character to remove
    {
        for(int i = 0; i < s2.size(); i++)
        {
            if(s1[i] != s2[i])
            {
                int j = i + 1;
                while(j < s1.size())
                {
                    if(s1[j] != s2[j - 1])
                    {
                        return false;
                    }
                    j++;
                }
                return true;
            }
        }
        // if the loop is done
        // the the only different character is the last character of s1
        return true;
    }
    else if(s1.size() == s2.size() - 1) // check for a character to insert
    {
        for(int i = 0; i < s2.size(); i++)
        {
            if(s2[i] != s1[i])
            {
                int j = i + 1;
                while(j < s2.size())
                {
                    if(s2[j] != s1[j - 1])
                    {
                        return false;
                    }
                    j++;
                }
                return true;
            }
        }
        // if the loop is done
        // the the only different character is the last character of s2
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    assert(isOneAway("pale", "ple")); // true
    assert(isOneAway("pales", "pale")); // true
    assert(isOneAway("pale", "bale")); // true

    assert(!isOneAway("pale", "bake")); // false

    return 0;
}
