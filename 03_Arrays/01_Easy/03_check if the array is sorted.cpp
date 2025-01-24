#include <bits/stdc++.h>
using namespace std;

int is_sorted(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        if(arr[i] >= arr[i-1]) {
            
        }
        else {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n; 
    cin >> n;
    int arr[n];
    for(int i = 0; i <= n - 1; i++) {
        cin >> arr[i];
    }

    cout << is_sorted(arr, n);
}