#include <bits/stdc++.h>
using namespace std;



// Optimal Approach - Binary Approach
// Time Complexity - O(logn)
// Space Complexity - O(1)
int floorSqrt(int n)
{
    int low = 1, high = n;
    // Binary search on the answers:
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n))
        {
            // eliminate the left half:
            low = mid + 1;
        }
        else
        {
            // eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}
