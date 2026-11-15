//anagram
#include<bits/stdc++.h> 
using namespace std; 

bool solution(string t, string s){
    if(t.size() != s.size()) return false;
    sort(t.begin(), t.end());
    sort(s.begin(), s.end());
    return t == s; 
}

int main(){
    string t = "hello";
    string s = "llohe";
    cout << (solution(t, s) ? "YES" : "NO");
    return 0; 
}