#include <bits/stdc++.h>
using namespace std;

// optimal approach
// Time Complexity: O(n)
int main() {
    int n;
    cin >> n;
    int arr[n];
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << max << endl;
    return 0;
}


// brute force approach - sort the array and return the last element
// Time Complexity: O(n * log n)
