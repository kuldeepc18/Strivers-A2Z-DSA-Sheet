#include <bits/stdc++.h>
using namespace std;



// Brute force approach
// TC: O(n1 log n) + O(n2 log n) + O(n1 + n2) --> O((n1 + n2)log(n1 + n2))
// SC: O(n1 + n2)   //if space of union is considered
// SC: O(1)  //if space of union is not considered
// vector < int > sortedArray(vector < int > a, vector < int > b) {
//     int n1 = a.size();
//     int n2 = b.size();

//     set<int> st;
//     for(int i = 0; i < n1; i++) {
//         st.insert(a[i]);
//     }

//     for(int i = 0; i < n2; i++) {
//         st.insert(b[i]);
//     }

//     vector<int> temp;
//     for(auto it : st) {
//         temp.push_back(it);
//     }

//     return temp;
// }





// Optimal approach --> using two pointers
// TC: O(n1 + n2)
// SC: O(1)
vector <int> FindUnion(int arr1[], int arr2[], int n1, int n2) {
    int i = 0, j = 0; // pointers
    vector <int> Union; // Union vector
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) // Case 1 and 2
        {
            if (Union.size() == 0 || Union.back() != arr1[i]) {
                Union.push_back(arr1[i]);
            }
            i++;
        } 
        else {    // case 3
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n1) // IF any element left in arr1
    {
        if (Union.back() != arr1[i]) {
            Union.push_back(arr1[i]);
        }
        i++;
    }

    while (j < n2) // If any elements left in arr2
    {
        if (Union.back() != arr2[j]) {
            Union.push_back(arr2[j]);
        }
        j++;
    }
    return Union;
}

int main()

{
    int n1 = 10, n2 = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
    vector <int> Union = FindUnion(arr1, arr2, n1, n2);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto & val: Union)
        cout << val << " ";
    return 0;
}

