// Variant - 1
// Problem Statement  --> There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

// Note: Start the array with positive elements.

#include <bits/stdc++.h>
using namespace std;

// Brute force
// Time Complexity: O(N+N/2)
// Space Complexity: O(N/2 + N/2) = O(N)
// vector<int> reArrangeBySign(vector<int> A, int n)
// {

//     vector<int> pos;
//     vector<int> neg;

//     for (int i = 0; i < n; i++)
//     {

//         if (A[i] > 0)
//             pos.push_back(A[i]);
//         else
//             neg.push_back(A[i]);
//     }

//     // Positives on even indices, negatives on odd.
//     for (int i = 0; i < n / 2; i++)
//     {

//         A[2 * i] = pos[i];
//         A[2 * i + 1] = neg[i];
//     }

//     return A;
// }




// Optimal Approach
// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> reArrangeBySign(vector<int> A)
{

    int n = A.size();

    vector<int> ans(n, 0);

    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++)
    {

        // Fill negative elements in odd indices and inc by 2.
        if (A[i] < 0)
        {
            ans[negIndex] = A[i];
            negIndex += 2;
        }

        // Fill positive elements in even indices and inc by 2.
        else
        {
            ans[posIndex] = A[i];
            posIndex += 2;
        }
    }

    return ans;
}

int main()
{

    vector<int> A{1, 2, -4, -5};

    vector<int> ans = reArrangeBySign(A);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}