#include <bits/stdc++.h>
using namespace std; 

string reverseString(string s){
    stack<char> st;
    for(char c : s) st.push(c);

    string result = "";
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result; 
}

int main(){
    string str = "hello";
    cout << "Chuoi ban dau: " << str << endl;
    cout << "Chuoi dao nguoc: " << reverseString(str) << endl; 
    return 0; 
}