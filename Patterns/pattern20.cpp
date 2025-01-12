#include <bits/stdc++.h>
using namespace std;

void pattern20(int n) {
    int initialSpaces = 2*n - 2;
    for(int i = 1; i <= 2*n - 1; i++) {
        
        int stars = i;
        if(i > n) {
            stars = 2*n - i;
        }

        //stars
        for(int j = 1; j <= stars; j++) {
            cout << "*" << " ";
        }

        //spaces
        for(int j = 1; j <= initialSpaces; j++) {
            cout << " ";
        }

        //stars
        for(int j = 1; j <= stars; j++) {
            cout << "*" << " ";
        }
        cout << endl;
        if(i < n) {
            initialSpaces -= 2;
        } else {
            initialSpaces += 2;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    pattern20(n);
    return 0;
}