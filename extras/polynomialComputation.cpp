#include <bits/stdc++.h>
using namespace std;

int power(int n, int raisedToPower){
    int value = 1;
    for(int i=0; i<raisedToPower; i++){
        value*=n;
    }
    return value;
}

// O(n^2) solution
int computePolynomialValue(vector<int> arr, int n, int x){
    int result = 0;
    for(int i=0; i<=n; i++){
        result+=arr[i]*power(x,n-i);
    }
    return result;
}

// O(n) solution
int computePolynomialValueQuicker(vector<int> arr, int n, int x){
   int result = arr[0];
   for(int i=1; i<arr.size(); i++){
        result = result*x + arr[i];
   }
   return result;
}

int main(){
    int n;
    cout << "Enter degree of polynomial: ";
    cin >> n;
    cout<<"Enter array of coefficients: " << endl;
    vector<int> arr;
    for(int i=0; i<=n; i++){
        cout << "Enter coefficient for x^" << n-i <<": ";
        int val;
        cin >> val;
        arr.push_back(val);
    }
    int x;
    cout << "Enter value of x: ";
    cin >> x;
    cout << computePolynomialValue(arr, n, x) << endl;
    cout << computePolynomialValueQuicker(arr, n, x) << endl;
}