#include <iostream> 
#include <vector> 
using namespace std; 

int main(){
    vector<string> products; 
    products.push_back("apple");
    products.push_back("orange");
    products.push_back("strawbarry");

    cout << "Danh sach san pham can mua la: " << endl;
    for(string p : products) {
        cout << p << endl;
    }
    return 0;
}