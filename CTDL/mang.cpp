#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int score[5] = {6, 7, 8, 9, 10};
    int sum = 0;
    for(int i = 0; i < 5; i++){
        sum += score[i];
    }
    cout << "Diem trung binh la: " << sum/5 << endl; 
    return 0; 
}