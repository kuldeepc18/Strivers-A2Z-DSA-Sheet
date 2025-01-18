#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// void gcd(int n1, int n2) {
//     int gcd = 1;
//     for(int i = 1; i <= min(n1, n2); i++) {
//         if(n1 % i == 0 && n2 % i == 0) {
//             gcd = i;
//         }
//     }
//     cout << "GCD is : "<< gcd;
// }


// Optimized approach
int gcd(int a,int b)
{
	//Write your code here
	while(a > 0 && b > 0) {
		if(a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	}
	if(a == 0) return b;
	return a;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    int result = gcd(n1, n2);
    cout << "GCD is : " << result;
}