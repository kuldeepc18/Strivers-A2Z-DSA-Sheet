#include <bits/stdc++.h>
using namespace std;

void maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // Maximum sum
    long long sum = 0;
    int start = 0, tempStart = 0, end = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            start = tempStart;
            end = i;
        }

        if (sum < 0) {
            sum = 0;
            tempStart = i + 1;
        }
    }

    cout << "Maximum Subarray Sum: " << maxi << endl;
    cout << "Subarray: [";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << (i < end ? ", " : "");
    }
    cout << "]" << endl;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    maxSubarraySum(arr, n);
    return 0;
}