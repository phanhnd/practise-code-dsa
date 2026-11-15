#include <bits/stdc++.h> 
using namespace std; 

int main(){
    stack<int> s; 
    string line; 

    while(getline(cin, line)){
        if(line == "#") break; 

        if(line.rfind("PUSH", 0) == 0){
            stringstream ss(line);
            string cmd; 
            int v; 
            ss >> cmd >> v; 
            s.push(v);
        } else if(line == "POP") {
            if(!s.empty()){
                cout << s.top() << "\n";
                s.pop();
            } else {
                cout << "NULL\n";
            }
        }
    }
    return 0; 
}