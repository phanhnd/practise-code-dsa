//Luu lich su trinh duyet
#include <iostream> 
#include <deque>
using namespace std; 

int main(){
    deque<string> history; 
    history.push_back("Learn web");
    history.push_back("Chat GPT learn ReactJs");
    history.push_back("CTDL & TTUD");

    cout << "Trang hien tai la: " << history.back() << endl; 
    history.pop_back();
    cout << "Quay lai: " << history.back() << endl; 
    return 0; 
}