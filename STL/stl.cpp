#include<bits/stdc++.h> // import all the required methods that we will be needing to solve most questions. 

using namespace std; /* automatically use the std namespace everywhere instead of having to type std:: 
before the functions that belong to the std namespace. For eg: If I want to use cin and I don’t type 
"using namespace std" then I will have to std::cin everywhere cin is used. */

void printName(){
    cout << "Nilesh";
}

int sum(int a, int b){
    return a+b;
}

void explainPair() { // useful for storing a pair of 2 values that always occur together
    pair<int, int> p = {1, 3}; // specify data type of pair of values
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int,int>> p2 = {1, {2,3}}; // we can also have pair containing pair objects
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    pair<int, int> pairArray[] = {{1,2}, {3,4}, {5,6}}; // can also create array of pairs
    for(int i = 0; i < sizeof(pairArray)/sizeof(pairArray[0]); i++){
        cout << pairArray[i].first << " " << pairArray[i].second << endl;
    } 
}

/* Arrays have constant size and cause an issue when you want to add a new element
after max size of array has already been reached. Vectors help solve this as they are 
dynamic in nature */
void explainVector() {
    vector<int> v; // creates an empty container
    v.push_back(1); // pushes 1 into the vector
    v.emplace_back(2); // dynamically increases the size and pushes 2. This is faster than push_back usually.

    vector<pair<int, int>> vecPair;
    vecPair.push_back({1,2});
    vecPair.emplace_back(3,4); // curly braces not needed for emplace_back

    vector<int> vInit(5,100); // generates vector of size 5 with all values as 100

    vector<int> vDefaultInit(5); // declares vector of size 5 with some default value (could be 0 or some garbage value)

    vector<int> vCopy(vInit); // creates another vector which is a copy of vInit

    // adding size while declaring a vector does not mean the size is fixed. It can dynamically increase.

    vector<int> arr = {1,2,3,4,5};
    cout << v[0] << endl; // we can use normal indexing to access elements

    for(auto it = arr.begin(); it!= arr.end(); it++){ // auto automatically helps decide the data type using the assigned value
        cout << *(it) << " "; // iterators going from start to end can also be used. iterator points to memory addresses, so we need to use * to get the value.
    }
    cout << endl;

    /*
    v.begin() points to the location of the first element
    v.end() points to one location after the last element
    v.rend() points to one location before the first element
    v.rbegin() points to the last element
    for(auto it = v.rbegin(); it!= v.rend(); it++) - this will start from the last element and move in reverse order
    towards the first element */

    cout << arr.back() << endl; // this will print the last element in the array

    for(int val : arr){ // can also use for-each
        cout << val << endl;
    }

    /*
    arr.erase(arr.begin()+1); // this will remove and rearrange elements of vector based on iterator position provided
    arr.erase(arr.begin(), arr.begin()+3); // this will erase the elements between index 0 and index 3. We have to give upper limit + 1
    */

    arr.insert(arr.begin(), 300); // inserts 300 at the beginning position
    arr.insert(arr.begin()+1, 2, 10); // inserts two 10s at index 1 and 2
    arr.insert(arr.begin(), v.begin(), v.end()); // insert vector v from begin to end into arr at begin position

    arr.pop_back(); // pops out the last element {10,20} -> {10}

    arr.clear(); // clears arr and makes it an empty vector

    arr.empty(); // returns true or false based on if array is empty
    
}

/*
Lists are mainly used because you can push elements quickly both at the back and the front. In vectors we mostly push at the end using push_back.
For pushing at the front, we need to use insert, which is a pretty slow operation compared to push_front for lists.
It uses a DOUBLY LINKED LIST whereas vectors use SINGLY LINKED LISTS which is what makes list operations faster to insert at front.
*/
void explainList(){
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    for(auto it = l.begin(); it != l.end(); it++){
        cout<< *(it) << endl;
    }
}

// Dequeue also has similar operations as vector

void explainStack(){
    stack<int> s;
    s.push(1); // pushes new element into stack based on LIFO
    s.push(2);
    s.push(3);
    s.push(3);
    cout<<s.top(); // gets topmost element of stack and does not do anything else
    s.pop(); s.pop(); // removes topmost element
    cout<<s.top()<<endl;
    s.size(); // gives size of stack
    s.empty(); // indicates if stack is empty or not
}

void explainQueue(){
    queue<int> q;
    q.push(1); // pushes new element into queue based of FIFO - {1}
    q.push(2); // {1,2}
    q.push(3); // {1,2,3}
    q.back(); // last element in queue - 3
    q.front(); // prints first element in queue - 1
    q.pop(); // removes first element - {2,3}
}

void explainPriorityQueue(){
    priority_queue<int> pq; // stores data in the form of a tree (also called max heap)
    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2} - automatically pushes in such a way that maximum number is at the "top" of the pq and the sorting is maintained
    pq.top(); // 8
    pq.pop(); // {5,2}

    // if we want to store in increasing order instead (also called min heap)
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.push(8); // {2,5,8}
    pq.top(); // 2
}

// everything remains sorted and no duplicate elements allowed
// tree is used internally
// logarithmic time complexity
void explainSet(){
    set<int> s;
    s.insert(5); // {5}
    s.insert(2); // {2,5}
    s.insert(8); // {2,5,8}
    s.insert(5); // {2,5,8} - no duplicates

    for(auto it = s.begin(); it != s.end(); it++){
        cout<<*(it)<<endl; // same as lists and vectors
    }

    auto it1 = s.find(5); // pointer to the address where 5 is stored
    auto it2 = s.find(6); // if an element is not in the set, then s.end() is returned - one address after the last element.

    s.erase(5); // {2.8} - deletes 5 and maintains the sorted order. 
    s.erase(s.find(8)); // {2} - We can also pass iterators to the erase function and it will work.

    // count will return either 1 or 0 as the element is either there once or not there at all
    s.count(2); // 1
    s.count(5); // 0
}

// same as set except duplicates are allowed
void explainMultiset(){
   multiset<int> s;
   s.insert(1); // {1}
   s.insert(1); // {1,1}
   s.insert(5); // {1,1,5}
   s.insert(2); // {1,1,2,5}
   // s.erase(s.find(1)) - erases only one 1 as we are using the pointer to a particular 1
   s.erase(1); // {2,5} - erases all 1s
}

// same as set except there is no sorting
// worst case complexity is O(N)
void explainUnorderedset(){
    unordered_set<int> s;
    s.insert(1); // {1}
    s.insert(1); // {1}
    s.insert(5); // {1,5}
    s.insert(2); // {1,5,2}
 }

 // key-value pairs like a dictionary
 // keys need to be unique, values can be duplicate. 
 // The unique keys are stored in sorted order
 void explainMap(){
    map<int, int> m;
    m[1] = 2; // creates key value pair 1:2
    m.insert({2,4});
    for(auto it : m){
        cout<<it.first<< " "<<it.second;
    }
    auto it = m.find(1); // input is the key. points at m.end() if element does not exist
 }

/* Multimap and unordered maps are same as regular maps. Except multimaps have duplicate keys allowed. The keys are still sorted. m[key] cannot be used
anymore due to the duplicacy. Unordered maps have no sorting but duplicates are also not allowed
*/

// creating custom comparison functions
// below one returns in descending order of second elements
bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second > p2.second){
        return true; // true coz we want in descending order
    }
    else
        return false;
}

void explainExtra(){
    vector<int> arr = {1,6,2,1,7,4};
    sort(arr.begin(), arr.end()); // in built function to sort vectors / lists in nlogn time. we can also pass subarrays by passing the right iterators 
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout << *(it) << " ";
    }
    cout<<endl;

    // sort(arr.begin(), arr.end(), greater<int>); - sorts in descending order
    // sort(arr.begin(), arr.end(), comp); // if we want to create some custom rules for comparison and sort accordingly

    // eg: sort a vector of pairs based on the second value
    vector<pair<int, int>> v = {{1,2}, {2,3}, {4,1}, {7,6}};
    sort(v.begin(), v.end(), comp);
    for(auto it = v.begin(); it != v.end(); it++){
        cout<< it -> first << " " << it -> second << endl; 
        // we can also do (*it).first but the above way is more readable
        // *(it).first won't work because . has higher precedence than * so it will evaluate *(it.first)
    }

    // finding the number of 1s in binary equivalent of number
    // __builtin__popcountll for long numbers
    int num = 9; // 9 is 00001001
    cout << "Number of 1s: " << __builtin_popcount(num) << endl; // so this should print 2

    // getting permutations of a string
    // next_permutation returns a true if more permutations exist. Otherwise it returns a false.
    // it modifies the original string to become the next permutation.
    string s = "123"; // 123, 132, 213, 231, 312, 321 (6 possible permutations)
    cout << s << endl;
    while(next_permutation(s.begin(), s.end())){
        cout << s << endl;
    }

    // finding max and min element in a vector
    vector<int> maxV = {4,5,1,6,2,7};
    int max = *max_element(maxV.begin(), maxV.end());
    cout << max << endl;
    int min = *min_element(maxV.begin(), maxV.end());
    cout << min << endl;
}



int main(){
    //printName();
    //cout<<sum(2,3);
    explainExtra();
    return 0;
}

