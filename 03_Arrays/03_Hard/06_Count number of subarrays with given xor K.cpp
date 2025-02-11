#include <bits/stdc++.h>
using namespace std;



// Brute force
// Time complexity: O(n^3)
// Space complexity: O(1)
// int subarraysWithXorK(vector<int> a, int k)
// {
//     int n = a.size(); // size of the given array.
//     int cnt = 0;

//     // Step 1: Generating subarrays:
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {

//             // step 2:calculate XOR of all
//             //  elements:
//             int xorr = 0;
//             for (int K = i; K <= j; K++)
//             {
//                 xorr = xorr ^ a[K];
//             }

//             // step 3:check XOR and count:
//             if (xorr == k)
//                 cnt++;
//         }
//     }
//     return cnt;
// }




// better approach
// Time complexity: O(n^2)
// Space complexity: O(1)
// int subarraysWithXorK(vector<int> a, int k) {
//     int n = a.size(); //size of the given array.
//     int cnt = 0;

//     // Step 1: Generating subarrays:
//     for (int i = 0; i < n; i++) {
//         int xorr = 0;
//         for (int j = i; j < n; j++) {

//             //step 2:calculate XOR of all
//             // elements:
//             xorr = xorr ^ a[j];

//             // step 3:check XOR and count:
//             if (xorr == k) cnt++;
//         }
//     }
//     return cnt;
// }




// Optimal approach - using hashing
// Time complexity: O(n) or O(nlogn) depending on the map used
// Space complexity: O(n)
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}


int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}
