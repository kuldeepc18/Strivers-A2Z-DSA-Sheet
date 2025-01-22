#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, string &s) {
    if(i >= s.size() / 2) return true;
    if(s[i] != s[s.size() - i - 1]) return false;
    return isPalindrome(i + 1, s);
}

int main() {
    string s;
    cin >> s;
    cout << isPalindrome(0, s) << endl;
    return 0;
}



// to check if a long sentence is palindrome or not
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int left = 0, right = s.size() - 1;
//         while(left < right) {
//             if(!isalnum(s[left])) {
//                 left++;
//             }
//             else if(!isalnum(s[right])) {
//                 right--;
//             }
//             else if(tolower(s[left]) != tolower(s[right])) {
//                 return false;
//             }
//             else {
//                 left++;
//                 right--;
//             }
//         }
//         return true;
//     }
// };