#include <bits/stdc++.h>
using namespace std;

bool iterativeLinearSearch(vector<int> arr, int searchElement) {
    if(arr.size() == 0){
        return false;
    }
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] == searchElement){
            cout << "Element found at index: " << i << endl;
            return true;
        }
    }
    return false;
}

bool recursiveLinearSearch(vector<int> arr, int start, int end, int searchElement){
    if(start==end){
        return false;
    }
    if(arr[start] == searchElement){
        cout << "Element found at index: " << start << endl;
        return true;
    }
    return recursiveLinearSearch(arr, start+1, end, searchElement);
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
    if(!iterativeLinearSearch(arr, searchElement)){
        cout << "Element not found!" << endl;
    }
    if(!recursiveLinearSearch(arr, 0, arr.size(), searchElement)){
        cout << "Element not found!" << endl;
    }
    return 0;
}