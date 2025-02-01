// Variant - 2
// Problem Statement --> There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.

// Note: Start the array with positive elements.

// Time Complexity: O(2*N)
// Space Complexity:  O(N/2 + N/2) = O(N)
#include <bits/stdc++.h>
using namespace std;

vector<int> reArrangeBySign(vector<int> A, int n)
{

    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < n; i++)
    {

        if (A[i] > 0)
            pos.push_back(A[i]);
        else
            neg.push_back(A[i]);
    }

    if (pos.size() < neg.size())
    {

        // First, fill array alternatively till the point
        // where positives and negatives are equal in number.
        for (int i = 0; i < pos.size(); i++)
        {

            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }

        // Fill the remaining negatives at the end of the array.
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {

            A[index] = neg[i];
            index++;
        }
    }

    else
    {

        // First, fill array alternatively till the point
        // where positives and negatives ar equal in number.
        for (int i = 0; i < neg.size(); i++)
        {

            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }

        // Fill the remaining positives at the end of the array.
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {

            A[index] = pos[i];
            index++;
        }
    }
    return A;
}

int main()
{

    int n = 6;
    vector<int> A{1, 2, -4, -5, 3, 4};

    vector<int> ans = reArrangeBySign(A, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}