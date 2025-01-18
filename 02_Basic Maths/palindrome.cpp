#include <bits/stdc++.h>
using namespace std;

void palindrome(int n) {
    int revNum = 0;
    int dup = n;
    while(n > 0) {
        int lastDigit = n % 10;
        revNum = (revNum * 10) + lastDigit;
        n = n / 10;
    }
    if(dup == revNum) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    palindrome(n);
    return 0;
}