#include<bits/stdc++.h> 
using namespace std;




// Brute force -> TC: O(n^2), SC: O(1)
// vector<int> majorityElement(vector<int> v)
// {
//     int n = v.size();
//     vector<int> ls;

//     for (int i = 0; i < n; i++)
//     {
//         if (ls.size() == 0 || ls[0] != v[i])
//         {
//             int cnt = 0;
//             for (int j = 0; j < n; j++)
//             {
//                 if (v[j] == v[i])
//                 {
//                     cnt++;
//                 }
//             }
//             if (cnt > (n / 3))
//                 ls.push_back(v[i]);
//         }

//         if (ls.size() == 2)
//             break;
//     }

//     return ls;
// }





// Better approach 
// TC: O(n*logn) -- ordered map ; O(n) -- unordered map best/average case ; O(n^2) -- unordered map worst case
// SC: O(1)

// vector<int> majorityElement(vector<int> v)
// {
//     int n = v.size();
//     vector<int> ls;

//     map<int, int> mpp;
//     int mini = int(n / 3) + 1;

//     for (int i = 0; i < n; i++)
//     {
//         mpp[v[i]]++;

//         if (mpp[v[i]] == mini)
//         {
//             ls.push_back(v[i]);
//         }
//         if (ls.size() == 2)
//             break;
//     }

//     return ls;
// }





// Optimal approach
// TC: O(n) + O(n) = O(n), SC: O(1)

vector<int> majorityElement(vector<int> v)
{
    int n = v.size(); 

    int cnt1 = 0, cnt2 = 0; 
    int el1 = INT_MIN;     
    int el2 = INT_MIN;      

    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el2 != v[i])
        {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i])
        {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1)
            cnt1++;
        else if (v[i] == el2)
            cnt2++;
        else
        {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls;

    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == el1)
            cnt1++;
        if (v[i] == el2)
            cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini)
        ls.push_back(el1);
    if (cnt2 >= mini)
        ls.push_back(el2);

    return ls;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}
