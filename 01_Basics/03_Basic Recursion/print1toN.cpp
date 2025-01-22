#include <bits/stdc++.h>
using namespace std;

int c = 1;
void printNos(int n) {  
    if (c > n) return;
    cout << c << " ";
    c++;
    printNos(n);
}




// printing 1 to n using backtracking
// void print1toN(int i, int n) {
//     if(i < n) return;
//     print1toN(i - 1, n);
//     cout << i << " ";
// }
// in main function take input n and call print1toN(n, n);

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    printNos(n);
    return 0;
}