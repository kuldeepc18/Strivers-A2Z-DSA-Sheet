#include<bits/stdc++.h>
using namespace std;

// Brute Force
// TC: O(n^2)
// SC: O(1)
// int solve(vector<int>& a) {
//     int maxLen = 0;
//     unordered_map<int, int> sumIndexMap;
//     int sum = 0;

//     for (int i = 0; i < a.size(); i++) {
//         sum += a[i];

//         if (sum == 0) {
//             maxLen = i + 1;
//         } else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
//             maxLen = max(maxLen, i - sumIndexMap[sum]);
//         } else {
//             sumIndexMap[sum] = i;
//         }
//     }

//     return maxLen;
// }





// Optimal Approach
// TC: O(n)
// SC: O(n)

int maxLen(vector<int> A)
{
    int n = A.size();
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }

    return maxi;
}

int main()
{
    vector<int> a = {9, -3, 3, -1, 6, -5};
    int ans = maxLen(a); 
    cout << "Length: " << ans << endl;

    return 0;
}