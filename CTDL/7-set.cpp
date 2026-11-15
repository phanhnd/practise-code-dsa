//Luu danh sach ten nguoi dung khong trung lap
#include <iostream>
#include <set> 
using namespace std;

int main(){
    set<string> names =  {"Alice", "Bob", "Luxyfer", "Bob"};
    cout << "Danh sach ten khong trung lap: \n";
    for(auto& name : names) cout << name << endl; 
    return 0;  
}