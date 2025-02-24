#include <bits/stdc++.h>
using namespace std;



// Optimal Approach - Binary Search 
// Time Complexity - O(logN)
// Space Complexity - O(1)
int findPeakElement(vector<int>& arr) {

    int n = arr.size();
    // Edge cases
    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        // if arr[mid] is peak
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }

        // mid is on increasing curve and peak is on right of it.
        else if (arr[mid] > arr[mid - 1]) {
            low = mid + 1;
        }

        // mid is on decreasing curve and peak is on left of it.
        else if (arr[mid] > arr[mid + 1]) {
            high = mid - 1;
        }

        // if mid is between both increasing or decreasing curve then move
        // to any of the side
        else {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}

