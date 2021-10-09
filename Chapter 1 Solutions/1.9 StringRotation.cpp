#include<bits/stdc++.h>

using namespace std;

/*
    1.6 String Rotation:
    Assume that you have a method isSubstring which checks if one word is a substring of another. Given two strings,
    s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring
    (e.g., "waterbottle" is a rotation of "erbottlewat").
*/
bool isSubstring(string , string );

// first solution
// with multiple calls to isSubstring
// Time Complexity: O(N^2)
// Memory Complexity: O(1)
bool isRotation(string s1, string s2)
{
    int breakingIndex = -1;
    for(int i = 1; i <= s1.size(); i++)
    {
        if(!isSubstring(s1.substr(0, i), s2))
        {
            breakingIndex = i - 1;
            break;
        }
    }
    if(breakingIndex == -1)
    {
        return true;
    }
    return s1.substr(breakingIndex) + s1.substr(0, breakingIndex) == s2;
}

// intended solution
// I got to this solution after looking at the hints at CTCI
// Time Complexity: O(N)
bool isRotationIntended(string s1, string s2)
{
    return s1.size() == s2.size() && isSubstring(s2, s1 + s1);
}

bool isSubstring(string s1, string s2)
{
    if(s1.size() > s2.size())
    {
        return false;
    }
    if(s1.empty())
    {
        return true;
    }
    for(int i = 0; i <= s2.size() - s1.size(); i++)
    {
        if(s2.substr(i, s1.size()) == s1)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    assert(isRotation("waterbottle", "erbottlewat"));
    assert(!isRotation("waterbottle", "erbottlewate"));

    assert(isRotationIntended("waterbottle", "erbottlewat"));
    assert(!isRotationIntended("waterbottle", "erbottlewate"));
    return 0;
}
