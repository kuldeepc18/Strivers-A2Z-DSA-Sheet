#include <bits/stdc++.h>
using namespace std;




//Brute Force Approach
//Time Complexity: O(n^3)
//Space Complexity: O(1)
// int getLongestSubarray(vector<int>& a, long long k) {
//     int n = a.size(); // size of the array.

//     int len = 0;
//     for (int i = 0; i < n; i++) { // starting index
//         for (int j = i; j < n; j++) { // ending index
//             // add all the elements of
//             // subarray = a[i...j]:
//             long long s = 0;
//             for (int K = i; K <= j; K++) {
//                 s += a[K];
//             }

//             if (s == k)
//                 len = max(len, j - i + 1);
//         }
//     }
//     return len;
// }





//Brute Force Approach ---> using two loops
//Time Complexity: O(n^2)
//Space Complexity: O(1)
// int getLongestSubarray(vector<int>& a, long long k) {
//     int n = a.size(); // size of the array.

//     int len = 0;
//     for (int i = 0; i < n; i++) { // starting index
//         long long s = 0; // Sum variable
//         for (int j = i; j < n; j++) { // ending index
//             // add the current element to
//             // the subarray a[i...j-1]:
//             s += a[j];

//             if (s == k)
//                 len = max(len, j - i + 1);
//         }
//     }
//     return len;
// }





//Better Approach ---> using hashing and prefix sum
//Time Complexity: O(n logn) --> for ordered map     &&    O(n) --> for unordered map(if no collisions)     &&   O(n^2) --> for unordered map(if collisions)
//Space Complexity: O(1)
// int getLongestSubarray(vector<int>& a, long long k) {
//     int n = a.size(); // size of the array.

//     map<long long, int> preSumMap;
//     long long sum = 0;
//     int maxLen = 0;
//     for (int i = 0; i < n; i++) {
//         //calculate the prefix sum till index i:
//         sum += a[i];

//         // if the sum = k, update the maxLen:
//         if (sum == k) {
//             maxLen = max(maxLen, i + 1);
//         }

//         // calculate the sum of remaining part i.e. x-k:
//         long long rem = sum - k;

//         //Calculate the length and update maxLen:
//         if (preSumMap.find(rem) != preSumMap.end()) {
//             int len = i - preSumMap[rem];
//             maxLen = max(maxLen, len);
//         }

//         //if the sum previously not there in the map, then add it:
//         if (preSumMap.find(sum) == preSumMap.end()) {
//             preSumMap[sum] = i;
//         }
//     }

//     return maxLen;
// }





//Optimal Approach ---> two pointers
//Time Complexity: O(2n)
//Space Complexity: O(1)
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}


