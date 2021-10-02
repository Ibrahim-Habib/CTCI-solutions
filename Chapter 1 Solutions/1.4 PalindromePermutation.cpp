#include<bits/stdc++.h>

using namespace std;

/*
    1.4 Palindrome Permutation:
    Given a string, write a function to check if it is a permutation of a palindrome.
    A palindrome is a word or phrase that is the same forwards and backwards.
    A permutation is a rearrangement of letters. The palindrome doesn't need to be limited to just dictionary words
    EXAMPLE
    Input: Tact Coa
    Output: True(permutations: "Taco cat", "atco cta", etc.)
*/

// solution using count array
// assuming that characters would be alphabetical lower case letters
// Time Complexity: O(N)
bool isPalindromePermutation(string s)
{
    int charFrequency[26];
    for(int i = 0; i < 26; i++)
    {
        charFrequency[i] = 0;
    }

    // count every non-space character
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            continue;
        }
        charFrequency[s[i] - 'a']++;
    }

    int oddFrequenciesCount = 0;
    for(int i = 0; i < 26; i++)
    {
        oddFrequenciesCount += charFrequency[i] % 2;
    }

    return oddFrequenciesCount <= 1;
}

int main()
{
    string pal1 = "madam";
    string pal2 = "mamad";
    string pal3 = "tact coa";
    string notPal = "this is not a palindrome permutation";

    assert(isPalindromePermutation(pal1));
    assert(isPalindromePermutation(pal2));
    assert(isPalindromePermutation(pal3));

    assert(!isPalindromePermutation(notPal));

    return 0;
}
