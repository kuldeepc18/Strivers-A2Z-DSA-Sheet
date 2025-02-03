#include <bits/stdc++.h>
using namespace std;



// brute -> for an element , search its next element in the array using Linear search



// better
// int longestConsecutive(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     int n = nums.size();
//     int lastSmaller = INT_MIN;
//     int cnt = 0;
//     int longest = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (nums[i] - 1 == lastSmaller)
//         {
//             cnt++;
//             lastSmaller = nums[i];
//         }
//         else if (nums[i] == lastSmaller)
//         {
//             continue;
//         }
//         else if (nums[i] != lastSmaller)
//         {
//             cnt = 1;
//             lastSmaller = nums[i];
//         }

//         longest = max(longest, cnt);
//     }

//     return longest;
// }





// optimal --> using set data structure
// Time complexity: O(N) + O(2N) = O(3N)
// Space complexity: O(N)

int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;

    int longest = 1;
    unordered_set<int> st;
    // put all the array elements into set:
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }

    // Find the longest sequence:
    for (auto it : st)
    {
        // if 'it' is a starting number:
        if (st.find(it - 1) == st.end())
        {
            // find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}