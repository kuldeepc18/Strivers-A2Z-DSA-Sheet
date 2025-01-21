#include <bits/stdc++.h>
using namespace std;

// recursive function
int fact(int n) {
    if(n == 0) return 1;
    return n * fact(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}




// print factorial less then or equal to n 
// vector<long long> factorialNumbers(long long n) {
//     vector<long long> v;
//     long long fact = 1;
//     for(long long i = 1; i <= n; i++) {
//         fact = fact * i;
//         v.push_back(fact);
//         if(v[i - 1] > n) {
//             v.pop_back();
//             break;
//         }
//     }
//     return v;
// }