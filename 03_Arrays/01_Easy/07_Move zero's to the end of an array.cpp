#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(2n)
// Space Complexity: O(n)
// void moveZeroes(int arr[], int n) {
    
//     // step - 1
//     vector<int> temp;
//     for(int i = 0; i < n; i++) {
//         if(arr[i] != 0) {
//             temp.push_back(arr[i]);
//         }
//     }

//     // step - 2
//     int nonZeros = temp.size();
//     for(int i = 0; i < nonZeros; i++) {
//         arr[i] = temp[i];
//     }

//     // step - 3
//     for(int i = nonZeros; i < n; i++) {
//         arr[i] = 0;
//     }   
// }


// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     moveZeroes(arr, n);
//     for(int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }





// Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> moveZeros(int n, vector<int> a) {
    int j = -1;
    //place the pointer j:
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    //no non-zero elements:
    if (j == -1) return a;

    //Move the pointers i and j
    //and swap accordingly:
    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}


int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeros(n, arr);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}

