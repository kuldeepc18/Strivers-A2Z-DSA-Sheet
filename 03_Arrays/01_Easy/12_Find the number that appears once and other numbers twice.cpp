#include <bits/stdc++.h>
using namespace std;



//Brute force approach
//Time complexity: O(n^2)
//Space complexity: O(1)
// int getSingleElement(vector<int> &arr) {
//     // Size of the array:
//     int n = arr.size();

//     //Run a loop for selecting elements:
//     for (int i = 0; i < n; i++) {
//         int num = arr[i]; // selected element
//         int cnt = 0;

//         //find the occurrence using linear search:
//         for (int j = 0; j < n; j++) {
//             if (arr[j] == num)
//                 cnt++;
//         }

//         // if the occurrence is 1 return ans:
//         if (cnt == 1) return num;
//     }

//     //This line will never execute
//     //if the array contains a single element.
//     return -1;
// }




//Better approach - 1
//Time complexity: O(3N)
//Space complexity: O(maxi)
// int getSingleElement(vector<int> &arr) {

//     //size of the array:
//     int n = arr.size();

//     // Find the maximum element:
//     int maxi = arr[0];
//     for (int i = 0; i < n; i++) {
//         maxi = max(maxi, arr[i]);
//     }

//     // Declare hash array of size maxi+1
//     // And hash the given array:
//     vector<int> hash(maxi + 1, 0);
//     for (int i = 0; i < n; i++) {
//         hash[arr[i]]++;
//     }

//     //Find the single element and return the answer:
//     for (int i = 0; i < n; i++) {
//         if (hash[arr[i]] == 1)
//             return arr[i];
//     }

//     //This line will never execute
//     //if the array contains a single element.
//     return -1;
// }





//Better approach - 2
//Time complexity: O(NlogM) + O(M) ---> M is the size of the map i.e (N/2 + 1)
//Space complexity: O(N/2 + 1)
// int getSingleElement(vector<int> &arr) {

//     //size of the array:
//     int n = arr.size();

//     // Declare the hashmap.
//     // And hash the given array:
//     map<int, int> mpp;
//     for (int i = 0; i < n; i++) {
//         mpp[arr[i]]++;
//     }

//     //Find the single element and return the answer:
//     for (auto it : mpp) {
//         if (it.second == 1)
//             return it.first;
//     }

//     //This line will never execute
//     //if the array contains a single element.
//     return -1;
// }





//Optimal approach
//Time complexity: O(N)
//Space complexity: O(1)
int getSingleElement(vector<int> &arr) {
    //size of the array:
    int n = arr.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}




int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}

