#include <bits/stdc++.h> 
using namespace std; 

bool check(vector<char>& cs){
    stack<char> s; 
    for(char c : cs){
        if(c == '{' || c == '[' || c == '('){
            s.push(c);
        } else {
            if(s.empty()) return false; 

            char top = s.top();
            if((c == ')' && top == '(') ||
               (c == ']' && top == '[') ||
               (c == '}' && top == '{')) {
                s.pop();
            } else {
                return false; 
            }
        }
    }
    return s.empty();
}

int main(){
    vector<char> cs = {'{', '[', '}', ')'};
    if(check(cs)) cout << "Valid\n";
    else cout << "Invalid\n";
    return 0;
}