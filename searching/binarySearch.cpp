#include <bits/stdc++.h>
using namespace std;

bool iterativeBinarySearch(vector<int> arr, int searchElement) {
    if(arr.size()==0){
        return false;
    }
    int start = 0;
    int end = arr.size();
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==searchElement){
            cout << "Element found at index: " << mid << endl;
            return true;
        }
        else if(arr[mid]>searchElement){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return false;
}

bool recursiveBinarySearch(vector<int> arr, int start, int end, int searchElement){
    if(start > end || arr.size()==0){
        return false;
    }
    int mid = (start+end)/2;
    if(arr[mid]==searchElement){
        cout << "Element found at index: " << mid << endl;
        return true;
    }
    else if(arr[mid]>searchElement){
        return recursiveBinarySearch(arr, start, mid-1, searchElement);
    }
    else{
        return recursiveBinarySearch(arr, mid+1, end, searchElement);
    }
}

// find is O(N) worst case for vectors and arrays
// find is faster in unordered sets compared to vector because of the way sets are initialized
// find is O(logN) worst case for sorted data types like set / sorted array / map because then it can use binary search
bool searchForAnElementInACodingRound(vector<int> arr, int searchElement){
    auto it = find(arr.begin(), arr.end(), searchElement);
    if(it!=arr.end()){
        cout << "Element found at index: " << distance(arr.begin(), it) << endl;
        return true;
    }
    return false;
}

int main(){
    vector<int> arr;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter values for the array: " << endl;
    for(int i = 0; i<n; i++){
        int val;
        cout << "Enter value: ";
        cin >> val;
        arr.push_back(val);
    }
    int searchElement;
    cout << "Enter element to search for: ";
    cin >> searchElement;
    sort(arr.begin(), arr.end()); // as binary search only works on sorted arrays
    if(!iterativeBinarySearch(arr, searchElement)){
        cout << "Element not found!" << endl;
    }
    if(!recursiveBinarySearch(arr, 0, arr.size(), searchElement)){
        cout << "Element not found!" << endl;
    }
    if(!searchForAnElementInACodingRound(arr, searchElement)){
        cout << "Element not found!" << endl;
    }
    return 0;
}