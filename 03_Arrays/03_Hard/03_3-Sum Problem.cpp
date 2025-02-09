#include<bits/stdc++.h>
using namespace std;




// // brute force  TC --> O(n^3 + log(no. of unique triplets)), SC --> O(2 * no. of triplets)
// int n = nums.size();
// set<vector<int>> st;
// for (int i = 0; i < n; i++) {
//     for (int j = i + 1; j < n; j++) {
//         for (int k = j + 1; k < n; k++) {
//             if (nums[i] + nums[j] + nums[k] == 0) {
//                 vector<int> temp = {nums[i], nums[j], nums[k]};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//         }
//     }
// }
// vector<vector<int>> ans(st.begin(), st.end());
// return ans;




// better approach --> using hashing TC --> O(n^2 * logM) where M is size of hashset, SC --> O(n) + O(no. of unique triplets)
// vector<vector<int>> threeSum(vector<int>& nums) {
//     // hashing
//     int n = nums.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++) {
//         set<int> hashset; // reinitialized when i increments
//         for (int j = i + 1; j < n; j++) {
//             int third = -(nums[i] + nums[j]);
//             if (hashset.find(third) != hashset.end()) {
//                 vector<int> temp = {nums[i], nums[j], third};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }

//             hashset.insert(nums[j]);
//         }
//     }

//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }




// Optimal approach
// TC --> O(NlogN)+O(N2)
// SC --> O(no. of unique triplets)

vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
