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

int main(){
    //printName();
    //cout<<sum(2,3);
    explainPair();
    return 0;
}

