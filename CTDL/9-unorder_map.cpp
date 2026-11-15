#include <iostream> 
#include <unordered_map>
using namespace std; 

int main(){
    unordered_map<string, string> dictionary = {
        {"cat", "con meo"}, {"dog", "con cho"}, {"bird", "con chim"}
    };

    cout << "Nghia cua 'cat' la: " << dictionary["cat"] << endl;
    return 0; 
}