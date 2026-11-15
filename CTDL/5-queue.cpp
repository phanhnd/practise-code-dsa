#include <iostream> 
#include <queue> 
using namespace std; 

int main(){
    queue<string> q;
    q.push("A");
    q.push("B");
    q.push("C");

    cout << "Danh sach hang cho la: \n";
    while(!q.empty()){
        cout << q.front() << endl; 
        q.pop();
    }
    return 0; 
}