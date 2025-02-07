
#include <bits/stdc++.h>
using namespace std;

// Type - 1 : To find the element in the Pascal's Triangle at position (r,c)
//
// int nCr(int n, int r) {
//     long long res = 1;

//     // calculating nCr:
//     for (int i = 0; i < r; i++) {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return res;
// }

// int pascalTriangle(int r, int c) {
//     int element = nCr(r - 1, c - 1);
//     return element;
// }

// int main()
// {
//     int r = 5; // row number
//     int c = 3; // col number
//     int element = pascalTriangle(r, c);
//     cout << "The element at position (r,c) is: "
//             << element << "n";
//     return 0;
// }

// Type - 2 : To print the nth row of Pascal's Triangle where n is the row number
// void pascalTriangle(int n) {
//     long long ans = 1;
//     cout << ans << " "; // printing 1st element

//     //Printing the rest of the part:
//     for (int i = 1; i < n; i++) {
//         ans = ans * (n - i);
//         ans = ans / i;
//         cout << ans << " ";
//     }
//     cout << endl;
// }

// Type - 3 : To print the entire Pascal's Triangle upto n rows
vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); // inserting the 1st element

    // calculate the rest of the elements of a row:
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ans;

    // store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
