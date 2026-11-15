//Contains Duplicate 
#include<bits/stdc++.h> 
using namespace std; 

bool containsDuplicate(vector<int>& nums){
    unordered_set<int> seen; 
    for(int x : nums){
        if(seen.count(x)) return true; 
        seen.insert(x);
    }
    return false;
}

int main(){
    int n; 
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << (containsDuplicate(arr) ? "YES" : "NO");
    return 0; 
}