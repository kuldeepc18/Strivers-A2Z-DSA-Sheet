#include<bits/stdc++.h>
using namespace std;


// Brute Force Approach
// Time Complexity: O(n*m)
// Space Complexity: O(m)     // for visited array
// vector<int> intersectionOfArrays(vector<int> arr1, vector<int> arr2) {
//     vector <int> ans;
//     int n = arr1.size();
//     int m = arr2.size();
//     // to maintain visited
//     int visited[m] = {0}; 
//     int i = 0, j = 0;

//     for (i = 0; i < n; i++) {
      
//         for (j = 0; j < m; j++) {

//             if (arr1[i] == arr2[j] && visited[j] == 0) { 
      
//                 //if element matches and has not been matched with any other before
//                 ans.push_back(arr2[j]);
//                 visited[j] = 1;
//                 break;
//             } 
      
//             if (arr2[j] > arr1[i]) break; 
//                 //because array is sorted , element will not be beyond this
//         }
//     }
  
//     return ans;
// }





// Optimal Approach
// Time Complexity: O(n+m)
// Space Complexity: O(1)
vector<int> intersectionOfArrays(vector<int> arr1, vector<int> arr2) {
    vector <int> ans;
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0; 

    // to traverse the arrays
    while (i < n && j < m) {
      
        //if current element in i is smaller
        if (arr1[i] < arr2[j]) { 
            i++;
        } 
        else if (arr2[j] < arr1[i]) {
            j++;
        } 
        else {
        
            //both elements are equal
            ans.push_back(arr1[i]); 
            i++;
            j++;
        }
    }
  
    return ans;  
}



int main() {
    
    // Array Initialisation.
    vector <int> arr1 {1,2,3,3,4,5,6,7};
    vector <int> arr2 {3,3,4,4,5,8};

    vector<int> ans = intersectionOfArrays(arr1, arr2);
  
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}