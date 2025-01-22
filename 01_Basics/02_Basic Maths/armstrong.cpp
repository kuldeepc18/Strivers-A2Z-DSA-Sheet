#include <bits/stdc++.h>
using namespace std;

bool checkArmstrong(int n){
	//Write your code here
	int sum = 0;
	int copyn = n;
	int digits = 0;

	int temp = n;
	while(temp != 0) {
		digits++;
		temp = temp / 10;
	} 

	while(n != 0) {
		int lastDgt = n % 10;
		sum = sum + pow(lastDgt, digits);
		n = n / 10;
	}
	if(sum == copyn) return true;
	else return false;
}

int main() {
    int n;
    cin >> n;
    cout << checkArmstrong(n);
}