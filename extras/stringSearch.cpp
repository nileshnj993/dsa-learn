#include <bits/stdc++.h>
using namespace std;

int computeComparisons(string s, string x){
    int count = 0;
    int i = 0;
    int j;
    int tempI;
    bool flag = false;
    while(i<= (s.length() - x.length())){
        j=0;
        tempI = i;
        while(j<x.length()){
            if(s[tempI] == x[j]){
                tempI++;
                j++;
                count++;
            }
            else{
                count++;
                break;
            }
            if(j==x.length()){
                flag = true;
                cout << "Substring found in String at index: " << i << endl;
                return count;
            }
        }
        i++;
    }
    if(!flag){
        cout << "Substring not found in String!" << endl;
    }
    return count;
}

// if we have an array of substrings to search for in a string and return count of how many substrings are present in the string
// when find finds a match it returns index of first occurence of substring
// when it does not find a match it returns string::npos which corresponds to -1
int numOfStrings(vector<string> patterns, string word) {
    int count = 0;
    for(int i =0; i<patterns.size(); i++){
        if(word.find(patterns[i])!=-1){
            count++;
        }   
    }   
    return count;
}

int main(){
    string s;
    cin >> s;
    string x;
    cin >> x;
    cout << computeComparisons(s, x) << endl;
    return 0;
}