#include <bits/stdc++.h>
using namespace std;

void pattern5(int n) {
    for(int i = 1; i <= n; i++) {
		for(int j = n; j >= i; j--) {   // (int j=0; j=n-i+1; j++)
			cout << "* ";
		}
		cout << endl;
	}
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    pattern5(n);
}