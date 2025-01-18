#include <bits/stdc++.h>
using namespace std;

int countDigits(int n){
	// Write your code here.
	int count = 0;
	while(n > 0) {
		int lastDigits = n % 10;
		count++;
		n = n / 10;
	}	
	return count;
}

// Time Complexity: O(log(n)) where n is the number of digits in the number

// another way to count digit 
// int count = (int)(log10(n) + 1);
// return count;

int main() {
    int n;
    cin >> n;
    cout << countDigits(n) << endl;
    return 0;
}