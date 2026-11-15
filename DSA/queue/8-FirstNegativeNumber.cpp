#include <bits/stdc++.h> 
using namespace std; 

vector<int> firstNegativeInWindow(vector<int>& arr, int k){
    deque<int> q; //stroe indexes of negative numbers
    vector<int> result; 
    int n = arr.size();

    //Process first k elements
    for(int i = 0; i < k; i++){
        if(arr[i] < 0)
            q.push_back(i);
    }

    //Process rest of the array 
    for(int i = k; i < n; i++){
        if(!q.empty()){
            result.push_back(arr[q.front()]);
        } else {
            result.push_back(0);
        }

        //remove elements that are out of this window
        while(!q.empty() && q.front() <= i - k){
            q.pop_front();
        }

        if(arr[i] < 0){
            q.push_back(i);
        }
    }

    //Add answer for the last window
    if(!q.empty()){
        result.push_back(arr[q.front()]);
    } else {
        result.push_back(0);
    }

    return result; 
}

int main(){
    vector<int> arr = { 12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3; 

    vector<int> ans = firstNegativeInWindow(arr, k);
    for(int x : ans) cout << x << " ";
    return 0; 
}