//Dem so lan xuat hien cua tu
#include <iostream> 
#include <map> 
using namespace std; 

int main(){
    string words[] = {"cat", "dog", "pig", "bird", "cat", "cat"};
    map<string, int> freq; 
    for(auto & w: words) {
        freq[w]++;
    }
    cout << "Tan xuat suat hien cua cac tu do la: \n";
    for(auto & p : freq){
        cout << p.first << ": " << p.second << endl; 
    }
    return 0; 
}