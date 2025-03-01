#include <bits/stdc++.h>
using namespace std;



// Optimal Approach
// Time Complexity: Time Complexity: O(N * log(sum(weights[]) - max(weights[]) + 1)), where sum(weights[]) = summation of all the weights, max(weights[]) = maximum of all the weights, N = size of the weights array.
// Space Complexity: O(1)
int findDays(vector<int> &weights, int cap)
{
    int days = 1; // First day.
    int load = 0;
    int n = weights.size();
    for (int i = 0; i < n; i++)
    {
        if (load + weights[i] > cap)
        {
            days += 1;         // move to next day
            load = weights[i]; // load the weight.
        }
        else
        {
            // load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    // Find the maximum and the summation:
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int numberOfDays = findDays(weights, mid);
        if (numberOfDays <= d)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
