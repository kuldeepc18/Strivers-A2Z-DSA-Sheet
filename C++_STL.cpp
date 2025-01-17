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
    
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    for(auto it = v.begin(); it != v.end(); it++) {     //auto is used to automatically detect the data type of the iterator
        cout << *(it) << " ";
    }

    for(auto it : v) {      //for each loop
        cout << it << " ";
    }


    //deletion

    //{10, 20, 12, 23}
    v.erase(v.begin() + 1);     //erases the element at index 1 i.e {10, 12, 23}

    //{10, 20, 12, 23, 35}
    v.erase(v.begin() + 2, v.begin() + 4);    //erases the elements from index 2 to 4 i.e {10, 20, 35} {start, end(not included)}

    //insert
    vector<int>v(2, 100);   //{100, 100}
    v.insert(v.begin(), 300);   //{300, 100, 100}
    v.insert(v.begin() + 1, 2, 10);     //{300, 10, 10, 100, 100}

    //copy
    vector<int> copy(2, 50);    //{50, 50}
    v.insert(v.begin(), copy.begin(), copy.end());    //{50, 50, 300, 10, 10, 100, 100}

    //{10, 20}
    cout << v.size() << " ";    //2 - gives the size of the vector

    //{10, 20}
    v.pop_back();   //erases the last element which is 20 --> output :-  {10}

    //v1 -> {10, 20}  
    //v2 -> {30, 40}
    v1.swap(v2);    //swaps the elements of v1 and v2 || output :- v1 -> {30, 40} v2 -> {10, 20}

    v.clear();

    cout << v.empty() << " ";   //1 - returns 1 if the vector is empty else 0
}





//list is dynamic in nature and similar to vectors but it is doubly linked list
void explainList() {
    list<int> ls;

    ls.push_back(2);    //{2}
    ls.emplace_back(4);     //{2, 4}

    ls.push_front(5);   //{5, 2, 4}

    ls.emplace_front(3);    //{3, 5, 2, 4}

    //rest functions are same as vectors
    //begin, end, rbegin, rend, clear, insert, size, swap

}





// deque is similar to vectors
void explainDeque() {
    deque<int>dq;
    dq.push_back(1);    // {1}
    dq.emplace_back(2);     // {1, 2}
    dq.push_front(4);   // {4, 1, 2}
    dq.emplace_front(3);    // {3, 4, 1, 2}

    dq.pop_back();  // {3, 4, 1}
    dq.pop_front();     // {4, 1}

    dq.back();  // 1     // back() is used to get the last element
    dq.front();     // 4     // front() is used to get the first element

    // rest functions are same as vectors
    // begin, end, rbegin, rend, clear, insert, size, swap
}





// Stack is LIFO - Last In First Out
// push, pop, top operations have O(1) time complexity
void explainStack() {
    stack<int> st;
    st.push(1);     // {1}
    st.push(2);     // {2, 1}
    st.push(3);     // {3, 2, 1}
    st.push(3);     // {3, 3, 2, 1}
    st.emplace(5);  // {5, 3, 3, 2, 1}

    cout << st.top() << " ";    // prints 5     // top() is used to get the top element

    st.pop();   // st looks like {3, 3, 2, 1}

    cout << st.top();    // prints 3

    cout << st.size();   // prints 4

    cout << st.empty();  // prints 0

    stack<int> st1, st2;
    st1.swap(st2);  // swaps the elements of st1 and st2

}





// Queue is FIFO - First In First Out
void explainQueue() {
    queue<int> q;
    q.push(1);     // {1}
    q.push(2);     // {1, 2}
    q.emplace(4);   // {1, 2, 4}

    q.back() +=5;

    cout << q.back() << " ";    // prints 9

    //Q is {1, 2, 9}
    cout << q.front() << " ";   // prints 1

    q.pop();    //Q is {2, 9}

    cout << q.front() << " ";   // prints 2

    // size, swap, empty functions are same as stack
}





// Priority Queue is a queue in which the elements are in sorted order
// push - O(logn), pop - O(logn), top - O(1)
void explainPQ() {
    // Maximum Heap
    priority_queue<int>pq;

    pq.push(5);     // {5}
    pq.push(2);     // {5, 2}
    pq.push(8);     // {8, 5, 2}
    pq.emplace(10);    // {10, 8, 5, 2}

    cout << pq.top() << " ";    // prints 10

    pq.pop();   // {8, 5, 2}

    cout << pq.top() << " ";    // prints 8

    // size, swap, empty functions are same as others

    // Minimum Heap or Minimum Priority Queue
    priority_queue<int, vector<int>, greater<int>>pq;
    pq.push(5);     // {5}
    pq.push(2);     // {2, 5}
    pq.push(8);     // {2, 5, 8}
    pq.emplace(10);    // {2, 5, 8, 10}

    cout << pq.top() << " ";    // prints 2

}





// Set is a data structure that stores unique elements in a sorted manner
void explainSet() {
    set<int>st;
    st.insert(1);  // {1}
    st.insert(2);  // {1, 2}
    st.insert(2);  // {1, 2}
    st.insert(4);  // {1, 2, 4}
    st.insert(3);  // {1, 2, 3, 4}

    // Functionality of insert in vector 
    // can be used also, that only increases efficiency

    // begin(), end(), rbegin(), rend(), size(), 
    // empty() and swap() are same as those of above

    //{1, 2, 3, 4, 5}
    auto it = st.find(3);   // returns the iterator pointing to the element 3 i.e address of 3

    //{1, 2, 3, 4, 5}
    auto it = st.find(6);   // returns st.end() as 6 is not present in the set

    //{1, 4, 5}
    st.erase(5);    // erases the element 5    // takes logarithmic time

    int cnt = st.count(1);   // returns the total number of elements with value 1 else it returns 0

    auto it = st.find(3);      // it points to 3
    st.erase(it);   // it takes constant time

    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2);     // after erase {1, 4, 5}  [first, last) - last is not included

    // lower_bound() and upper_bound() function works in the same way as in vector it does.

    // This is the syntax
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);

}





//MultiSet is similar to set but it can store multiple elements with the same value
void explainMultiSet() {
    // Everything is same as set but it can store duplicate elements also

    multiset<int>ms;
    ms.insert(1);  // {1}
    ms.insert(1);  // {1, 1}
    ms.insert(1);  // {1, 1, 1}

    ms.erase(1);    // all 1's erased

    int cnt = ms.count(1);      // returns the total number of elements with value 1

    // only a single one erased
    ms.erase(ms.find(1));

    // ms.erase(ms.find(1), ms.find(1)+2);      // erases 2 occurence of ones

    // rest all functions are same as set

}





// Unordered Set stores element in an unordered manner and must be unique
// All operations are O(1) except in worst case it is O(n)
void explainUSet() {
    // unordered set<int>st;
    // lower_bound() and upper_bound() functions does not work, 
    // rest all functions are same as above 
    // it does not stores in any particular order, it has a better time complexity 
    // than set in most cases, except some when collision happens

}





// Map is a data structure that stores key value pairs | Key :- Unique, sorted order, any data type
void explainMap() {

    map<int, int> mpp;

    // map<int, pair<int, int>> mpp;

    // map<pair<int, int>, int> mpp;


    mpp[1] = 2;     //it store in key-value pairs as {1, 2}
    mpp.emplace({3, 1});

    mpp.insert({2, 4});

    mpp[{2, 3}] = 10;       // stores as {{2, 3}, 10}

    // output
    // {
    //     {1, 2}
    //     {2, 4}
    //     {3, 1}
    // }

    // accessing elements of map
    for(auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1];     // prints 2 | value corresponding to key 1
    cout << mpp[5];     // prints 0 or NULL

    auto it = mpp.find(3);      // returns the iterator(address) pointing to the key 3
    cout << *(it).second;       // * is the element i.e {3, 1} and `.second` prints the value 1

    auto it = mpp.find(5);      // as key 5 is not present in the map, it returns mpp.end()

    auto it = mpp.lower_bound(2);

    auto it = mpp.upper_bound(3);

    // erase, swap, size, empty functions are same as above
}





//
void explainMultimap() {
    // Everything is same as map, only it can store multiple keys and in sorted order
    // rest all functions are same as map
}





// unordered map stores key value pairs in an unordered manner
// stores unique keys in a randomized order
// All operations are O(1) except in worst case it is O(n)
void explainUnorderedMap() {
    // same as set and unordered_Set difference
}



bool comp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;

    //they are same
    if(p1.first  > p2.first) return true;
    return false;
}

// Algorithms on container
void explainExtra() {
    int a[5], n;
    vector<int> v;
    sort(a, a + n);     // sorts the array a from a[0] to a[n-1]
    sort(v.begin(), v.end());   // sorts the vector v from v.begin() to v.end()

    sort(a+2, a+4);     // sorts the array from a[2] to a[4]

    sort(a, a+n, greater<int>);    // sorts the array in descending order

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};

    // sort according to own_way
    // sort it according to second element 
    // if second element is same, then sort it according to first element in descending order

    sort(a, a+n, comp);     // comp is a comparator function that is defined above 


    // {{4, 1}, {2, 1}, {1, 2}}
    int num = 7;
    int cnt = __builtin_popcount(num);    // returns the number of set bits in the binary representation of the number   || 7 -> 111 -> prints 3

    long long num = 134657687653546;
    int cnt = __builtin_popcountll(num);  // same as above but for long long

    string s = "123";
    // To prints all the permutations, the string should be sorted
    sort(s.begin(), s.end());

    do {
        cout << s << endl;      // prints -> 123, 132, 213, 231, 312, 321
    } while(next_permutation(s.begin(), s.end()));    // prints all the permutations of the string

    int maxi = *max_element(a, a+n);    // max_element returns the address of the max element and * prints the value present at that address.

}




int main() {
    cout << " C++ STL " << endl;
    explainPair();
    explainVector();
    explainList();
    explainDeque();
    explainStack();
    explainQueue();
    explainPQ();
    explainSet();
    explainMultiSet();
    explainUSet();
    explainMap();
    explainMultimap();
    explainUnorderedMap();
    explainExtra();
}