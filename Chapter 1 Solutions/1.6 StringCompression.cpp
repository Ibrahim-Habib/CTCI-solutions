#include<bits/stdc++.h>

using namespace std;

/*
    1.6 String Compression:
    Implement a method to perform basic string compression using the counts of repeated characters.
    For example, the string aabcccccaaa would become a2b1c5a3.
    If the "compressed" string would not become smaller than the original string, your method should return
    the original string.
    You can assume the string has only uppercase and lowercase letters (a-z0.
*/

//helper function
string convertIntToString(int x)
{
    string ret = "";
    while(x > 0)
    {
        ret += ((char) ('0' + (x % 10)));
        x /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string compress(string s)
{
    char curCharacter = '@';
    int curCount = 0;
    string compressedString = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == curCharacter)
        {
            curCount++;
        }
        else
        {
            if(curCharacter != '@')
            {
               compressedString += curCharacter + convertIntToString(curCount);
            }
            curCharacter = s[i];
            curCount = 1;
        }
    }

    //last character(s)
    compressedString += curCharacter + convertIntToString(curCount);
    if(compressedString.size() < s.size())
    {
        return compressedString;
    }
    else
    {
        return s;
    }
}

int main()
{
    assert(compress("aabcccccaaa") == "a2b1c5a3");
    assert(compress("abcdefg") == "abcdefg");
    return 0;
}
