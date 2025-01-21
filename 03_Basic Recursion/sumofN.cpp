#include <bits/stdc++.h>
using namespace std;

//parameterised way
void sumofN(int i, int sum) {
    if(i < 1) {
        cout << sum << endl;
        return;
    }
    sumofN(i-1, sum+i);
}

//functional way
// void sumofN(int n) {
//     if(n == 0) {
//         return 0;
//     }
//     return n + sumofN(n - 1);
// }

int main() {
    int n;
    cin >> n;
    sumofN(n, 0);
}




// sum of series
// int sum = 0;
// int sumOfSeries(int n) {
//     // code here
//     if(n == 0) return 0;
//     sumOfSeries(n - 1);
//     sum += pow(n, 3);
//     return sum;
// }