#include <bits/stdc++.h>
using namespace std;




// brute force  --> using 4 nested loops then store the 4 elements in a temp variable and sort it and store in set so that only unique quadruplets will form and then store the elements from set to ans variable and return the ans.
// Time Complexity: O(N^4)
// Space Complexity: O(2 * no. of the quadruplets)




// Better approach --> using 3 loops and set data structure
// Time Complexity: O(N3*log(M)), where N = size of the array, M = no. of elements in the set.
// Space Complexity: O(2 * no. of the quadruplets)+O(N)
// vector<vector<int>> fourSum(vector<int> &nums, int target)
// {
//     int n = nums.size(); // size of the array
//     set<vector<int>> st;

//     // checking all possible quadruplets:
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             set<long long> hashset;
//             for (int k = j + 1; k < n; k++)
//             {
//                 // taking bigger data type
//                 // to avoid integer overflow:
//                 long long sum = nums[i] + nums[j];
//                 sum += nums[k];
//                 long long fourth = target - sum;
//                 if (hashset.find(fourth) != hashset.end())
//                 {
//                     vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 // put the kth element into the hashset:
//                 hashset.insert(nums[k]);
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }




// Optimal approach --> using 4 pointers approach
// Time Complexity: O(N^3)
// Space Complexity: O(no. of quadruplets)
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size(); // size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    // calculating the quadruplets:
    for (int i = 0; i < n; i++)
    {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    // skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }

    return ans;
}


int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
