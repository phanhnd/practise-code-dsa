#include <bits/stdc++.h> 
using namespace std; 

int main(){
    queue<int> q; 
    string line; 

    while(getline(cin, line)){
        if(line == "#") break; 

        if(line.rfind("PUSH", 0) == 0){
            stringstream ss(line);
            string cmd; 
            int v; 
            ss >> cmd >> v; 
            q.push(v);
        } else if(line == "POP"){
            if(!q.empty()){
                cout << q.front() << "\n";
                q.pop();
            } else {
                cout << "NULL\n";
            }
        }
    }
    return 0; 
}