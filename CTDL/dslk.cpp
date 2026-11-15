#include <iostream> 
using namespace std; 

struct Node {
    string action;
    Node* next;

    Node(string a, Node* n){
        action = a;
        next = n;
    }
};


int main(){
    Node* head = new Node("Open file", nullptr);
    head->next = new Node("Read meassage", nullptr);
    head->next->next = new Node("Close file", nullptr);

    cout << "History of action: \n" ;
    for(Node* p = head; p != nullptr; p=p->next){
        cout << p->action << endl; 
    }
    return 0; 
}
