#include <bits/stdc++.h>
using namespace std;

//Pairs
void explainPair() {

    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    pair<int, int> arr[] = { {1, 2}, {2, 5}, {5, 1} };
    cout << arr[1].second << endl;
}


//Vectors :- Dynamic in nature and similar to arrays
void explainVector() {

    vector<int> v;      //declaration

    v.push_back(1);     //insert element in the vector i.e {1}
    v.emplace_back(2);      //insert element at the end i.e {1, 2}

    vector<pair<int, int>> vec;  //vector of pairs
    vec.push_back({1, 2});      //first time insert in vector of pairs i.e { {1, 2} }
    vec.emplace_back(1, 2);     // curle brace is not required in emplace_back as it assumes it is a pair

    vector<int> v(5, 100);      //vector of size 5 with all elements as 100

    vector<int> v(5);    //vector of size 5 with all elements as 0 or any garbage value

    vector<int> v1(5, 20);  //vector of size 5 with all elements as 20

    vector<int> v2(v1);     //copy all elements of v1 to v2

    //accessing elements in the vector

    vector<int>::iterator it = v.begin();   //v.begin points to memory location of first element

    it++;
    cout << *(it) << " ";       //* is used to get the value at the memory location

    it = it + 2;
    cout << *(it) << " ";   

    vector<int>::iterator it = v.end();     //points to the memory location after the last element
    //never used below two iterators
    //vector<int>::iterator it = v.rend();    //points to the memory location before the first element
    //vector<int>::iterator it = v.rbegin();  //points to the last element and then if we do it++ it will point to second last element

    cout << v[0] << " ";    //accessing elements using [] operator

    cout << v.back() << " ";    //accessing last element of the vector

    //printing the vectors
    



}


int main() {
    cout << " C++ STL " << endl;
    explainPair();
}