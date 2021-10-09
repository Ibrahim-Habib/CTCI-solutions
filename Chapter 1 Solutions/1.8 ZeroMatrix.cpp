#include<bits/stdc++.h>

using namespace std;

/*
    1.8 Zero Matrix:
    Write an algorithm such that if an element in an MxN matrix is 0,
    its entire row and column are set to 0.
*/

// first loop is to find rows and columns which have zeros
// second loop is to assign 0 to elements whose rows or columns have 0
// Time complexity: O(NM)
// Memory complexity: O(N + M)
vector<vector<int> > getZeroMatrix(vector<vector<int> > m)
{
    if(m.empty())
    {
        return m;
    }
    vector<bool>rowHasZero = vector<bool>(m.size(), false);
    vector<bool>columnHasZero = vector<bool>(m[0].size(), false);
    for(int i = 0; i < m.size(); i++)
    {
        for(int j = 0; j < m[i].size(); j++)
        {
            if(m[i][j] == 0)
            {
                rowHasZero[i] = true;
                columnHasZero[j] = true;
            }
        }
    }

    for(int i = 0; i < m.size(); i++)
    {
        for(int j = 0; j < m[i].size(); j++)
        {
            if(rowHasZero[i] || columnHasZero[j])
            {
                m[i][j] = 0;
            }
        }
    }

    return m;
}

// helper function
void displayMatrix(vector<vector<int> > v)
{
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int> > v = {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};

    vector<vector<int> > v1 = {{1, 2, 3, 4, 5},
                                {4, 0, 6, 7, 8},
                                {7, 8, 9, 10, 11},
                                {12, 13, 14, 0, 16},
                                {8, 99, 13, 19, 25}};

    vector<vector<int> > v2 = {{0, 2, 3},
                            {4, 0, 6},
                            {7, 8, 9}};



    displayMatrix(v);
    displayMatrix(getZeroMatrix(v));
    cout << "-----------------------------------------------" << endl;
    displayMatrix(v1);
    displayMatrix(getZeroMatrix(v1));
    cout << "-----------------------------------------------" << endl;
    displayMatrix(v2);
    displayMatrix(getZeroMatrix(v2));
    cout << "-----------------------------------------------" << endl;
    return 0;
}
