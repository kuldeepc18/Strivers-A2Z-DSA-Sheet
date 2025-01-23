#include <bits/stdc++.h>
using namespace std;

// method - 1
void bubble_sort(int arr[], int n) {
    int didSwap = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0) {
            break;
        }
    }
}

// method - 2
// void bubbleSort(vector<int>& arr) {
//     // Your code here
//     int  n= arr.size();
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             if(arr[j] > arr[i]) {
//                 int temp = arr[j];
//                 arr[j] = arr[i];
//                 arr[i] = temp;
//             }
//         }
//     }
// }

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubble_sort(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}