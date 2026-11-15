//Kiem tra dau ngoac hop
#include <iostream> 
#include <stack> 
using namespace std; 

bool checkVar(string s){
    stack<char> st; 
    for(char c : s) {
        if(c == '(') st.push(c);
        else if (c == ')'){
            if(st.empty()) return 0; 
            if(st.top() == '(') st.pop();
        }
    }
    return st.empty();
}

int main(){
    string s = "(a+b)*c+d)";
    cout << (checkVar(s) ? "Hop le" : "Sai") << endl; 
    return 0; 
}