#include <iostream> 
#include <queue>
using namespace std; 

int main(){
    queue<int> q; 

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "front: " << q.front() << endl; 
    cout << "back: " << q.back() << endl; 
    cout << "size: " << q.size() << endl; 

    q.pop();
    cout << "front after pop: " << q.front() << endl; 
    return 0; 
}