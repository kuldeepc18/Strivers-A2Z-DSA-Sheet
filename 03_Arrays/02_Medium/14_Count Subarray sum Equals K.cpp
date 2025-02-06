#include <bits/stdc++.h>
using namespace std;

// brute force --> using 3 loops
// Time complexity: O(N^3)
// Space complexity: O(1)
// int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
// {
//     int n = arr.size(); // size of the given array.
//     int cnt = 0;        // Number of subarrays:

//     for (int i = 0; i < n; i++)
//     { // starting index i
//         for (int j = i; j < n; j++)
//         { // ending index j

//             // calculate the sum of subarray [i...j]
//             int sum = 0;
//             for (int K = i; K <= j; K++)
//                 sum += arr[K];

//             // Increase the count if sum == k:
//             if (sum == k)
//                 cnt++;
//         }
//     }
//     return cnt;
// }

// Better approach --> without using 3rd inner loop
// Time complexity: O(N^2)
// Space complexity: O(1)
// int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     int cnt = 0;        // Number of subarrays:

//     for (int i = 0; i < n; i++)
//     { // starting index i
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         { // ending index j
//             // calculate the sum of subarray [i...j]
//             // sum of [i..j-1] + arr[j]
//             sum += arr[j];

//             if (sum == k)
//                 cnt++;
//         }
//     }
//     return cnt;
// }





// Optimal approach --> using prefix sum
// Time complexity: O(N) --> unordered_map   or O(N*logN) --> ordered_map
// Space complexity: O(N)
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    map<int, int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return cnt;
}



int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}
