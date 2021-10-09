#include<bits/stdc++.h>

using namespace std;

/*
    1.7 Rotate Matrix:
    Given an image represented by a NxN matrix, where each pixel in the image is 4 bytes,
    write a method to rotate the image by 90 degrees, Can you do this in place?
*/

// assuming that the rotation is clockwise

// naive solution: copying the matrix to a new matrix
// Time Complexity: O(N^2)
// Memory Complexity: O(N^2)
void displayMatrix(vector<vector<int> >);

vector<vector<int> > rotateMatrix(vector<vector<int> > m)
{
    if(m.empty())
    {
        return m;
    }
    vector<vector<int> > result = vector<vector<int> > (m[0].size());
    for(int i = 0; i < result.size(); i++)
    {
        result[i] = vector<int>(m.size());
    }

    for(int i = 0; i < m.size(); i++)
    {
        for(int j = 0; j < m[i].size(); j++)
        {
            result[j][m.size() - i - 1] = m[i][j];
        }
    }

    return result;
}

// assuming that the rotation is clockwise

// rotating the matrix in place
// Time Complexity: O(N^2)
// Memory Complexity: O(1)
void rotateMatrixInPlace(vector<vector<int> >& m)
{
    int n = m.size();
    for(int layer = 0; layer < n / 2; layer++)
    {
        for(int j = layer; j < n - layer - 1; j++)
        {
            swap(m[layer][j], m[j][n - layer - 1]);
            swap(m[layer][j], m[n - layer - 1][n - j - 1]);
            swap(m[layer][j], m[n - j - 1][layer]);
        }

    }
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
                                {4, 5, 6, 7, 8},
                                {7, 8, 9, 10, 11},
                                {12, 13, 14, 15, 16},
                                {8, 99, 13, 19, 25}};
    vector<vector<int> > v2 = {{1, 2},
                            {4, 5}};
    vector<vector<int> > v3 = {{1}};

    cout << "Rotate Matrix by copying to a new matrix:" << endl;
    displayMatrix(v);
    displayMatrix(rotateMatrix(v));
    cout << "-----------------------------------------------" << endl;
    displayMatrix(v1);
    displayMatrix(rotateMatrix(v1));
    cout << "-----------------------------------------------" << endl;
    displayMatrix(v2);
    displayMatrix(rotateMatrix(v2));
    cout << "-----------------------------------------------" << endl;
    displayMatrix(v3);
    displayMatrix(rotateMatrix(v3));
    cout << "-----------------------------------------------" << endl;

    cout << "Rotate Matrix in place:" << endl;
    displayMatrix(v);
    rotateMatrixInPlace(v);
    displayMatrix(v);
    cout << "-----------------------------------------------" << endl;
    displayMatrix(v1);
    rotateMatrixInPlace(v1);
    displayMatrix(v1);
    cout << "-----------------------------------------------" << endl;
    displayMatrix(v2);
    rotateMatrixInPlace(v2);
    displayMatrix(v2);
    cout << "-----------------------------------------------" << endl;
    displayMatrix(v3);
    rotateMatrixInPlace(v3);
    displayMatrix(v3);
    cout << "-----------------------------------------------" << endl;
    return 0;
}
