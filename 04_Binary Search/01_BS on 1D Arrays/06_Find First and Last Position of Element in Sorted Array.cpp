#include <bits/stdc++.h>
using namespace std;


// Using lower_bound and upper_bound
// Time complexity: O(logn)
// Space complexity: O(1)
// class Solution
// {
// public:
//     int lowerBound(vector<int> arr, int n, int x)
//     {
//         int low = 0, high = n - 1;
//         int ans = n;

//         while (low <= high)
//         {
//             int mid = (low + high) / 2;
//             // maybe an answer
//             if (arr[mid] >= x)
//             {
//                 ans = mid;
//                 // look for smaller index on the left
//                 high = mid - 1;
//             }
//             else
//             {
//                 low = mid + 1; // look on the right
//             }
//         }
//         return ans;
//     }

//     int upperBound(vector<int> &arr, int n, int x)
//     {
//         int low = 0, high = n - 1;
//         int ans = n;

//         while (low <= high)
//         {
//             int mid = (low + high) / 2;
//             // maybe an answer
//             if (arr[mid] > x)
//             {
//                 ans = mid;
//                 // look for smaller index on the left
//                 high = mid - 1;
//             }
//             else
//             {
//                 low = mid + 1; // look on the right
//             }
//         }
//         return ans;
//     }

//     vector<int> searchRange(vector<int> &nums, int target)
//     {

//         // Optimal approach using binary search

//         int n = nums.size();
//         int lb = lowerBound(nums, n, target);
//         if (lb == n || (nums[lb] != target))
//             return {-1, -1};

//         return {lb, upperBound(nums, n, target) - 1};
//     }
// };



// Using simple binary search
// Time complexity: O(logn)
// Space complexity: O(1)
class Solution
{
public:
    int firstOccurence(vector<int> &arr, int n, int k)
    {
        int low = 0, high = n - 1;
        int first = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == k)
            {
                first = mid;
                high = mid - 1;
            }
            else if (arr[mid] < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return first;
    }

    int lastOccurence(vector<int> &arr, int n, int k)
    {
        int low = 0, high = n - 1;
        int last = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == k)
            {
                last = mid;
                low = mid + 1;
            }
            else if (arr[mid] < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return last;
    }

    vector<int> searchRange(vector<int> &arr, int target)
    {

        // Optimal approach using simple Binary Search
        int n = arr.size();
        int first = firstOccurence(arr, n, target);
        if (first == -1)
            return {-1, -1};
        int last = lastOccurence(arr, n, target);

        return {first, last};
    }
};