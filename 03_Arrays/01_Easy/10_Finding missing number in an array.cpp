#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach
// Time Complexity: O(N*N)
// Space Complexity: O(1)
// int missingNumber(vector<int>&a, int N) {

//     // Outer loop that runs from 1 to N:
//     for (int i = 1; i <= N; i++) {

//         // flag variable to check
//         //if an element exists
//         int flag = 0;

//         //Search the element using linear search:
//         for (int j = 0; j < N - 1; j++) {
//             if (a[j] == i) {

//                 // i is present in the array:
//                 flag = 1;
//                 break;
//             }
//         }

//         // check if the element is missing
//         //i.e flag == 0:

//         if (flag == 0) return i;
//     }

//     // The following line will never execute.
//     // It is just to avoid warnings.
//     return -1;
// }





//Better Approach
// Time Complexity: O(2N)
// Space Complexity: O(N)
// int missingNumber(vector<int>&a, int N) {

//     int hash[N + 1] = {0}; //hash array

//     // storing the frequencies:
//     for (int i = 0; i < N - 1; i++)
//         hash[a[i]]++;

//     //checking the freqencies for numbers 1 to N:
//     for (int i = 1; i <= N; i++) {
//         if (hash[i] == 0) {
//             return i;
//         }
//     }

//     // The following line will never execute.
//     // It is just to avoid warnings.
//     return -1;
// }





//Optimal Approach - 1
// Time Complexity: O(N)
// Space Complexity: O(1)
// int missingNumber(vector<int>&a, int N) {

//     //Summation of first N numbers:
//     int sum = (N * (N + 1)) / 2;

//     //Summation of all array elements:
//     int s2 = 0;
//     for (int i = 0; i < N - 1; i++) {
//         s2 += a[i];
//     }

//     int missingNum = sum - s2;
//     return missingNum;
// }

// int main()
// {
//     int N = 5;
//     vector<int> a = {1, 2, 4, 5};
//     int ans = missingNumber(a, N);
//     cout << "The missing number is: " << ans << endl;
//     return 0;
// }





//Optimal Approach - 2
// Time Complexity: O(N)
// Space Complexity: O(1)



#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&a, int N) {

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ a[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; //XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}



int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}

