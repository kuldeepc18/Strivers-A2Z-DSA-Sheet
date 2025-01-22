#include <bits/stdc++.h>
using namespace std;

void printSubSeq(int ind, vector<int> &ds, int arr[], int n) {
    if(ind == n) {
        for(auto it : ds) {
            cout << it << " ";
        }
        if(ds.size() == 0) {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    // take the particular index into the subsequence
    ds.push_back(arr[ind]);
    printSubSeq(ind + 1, ds, arr, n);
    ds.pop_back();

    // not take condition : this particular element is not added to the subsequence
    printSubSeq(ind + 1, ds, arr, n);
}

int main() {
    int n = 3;
    int arr[] = {3, 1, 2};
    vector<int> ds;
    printSubSeq(0, ds, arr, n);
}