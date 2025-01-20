#include <bits/stdc++.h>
using namespace std;

void printRevNo(int n) {
    if(n == 0) {
        return;
    }
    cout << n << " ";
    printRevNo(n-1);
}

int main() {
    int n;
    cin >> n;
    printRevNo(n);
}