#include <iostream> 
#include <vector> 
using namespace std; 

int main(){
    vector<int> friends[4];
    friends[0] = {1, 2};
    friends[1] = {0, 3};
    friends[2] = {0};
    friends[3] = {1};

    cout << "Ban cua A la (so 0): "; 
    for(int f : friends[0]) cout << f << " ";
    return 0; 
}