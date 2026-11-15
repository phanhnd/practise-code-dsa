#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int n; 
    cout << "Nhap menh gia tien can doi: ";
    cin >> n; 

    vector<int> coins = { 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    vector<int> used; 
    int count = 0; 

    for(int coin : coins) {
        while(n >= coin){
            n -= coin; 
            used.push_back(coin);
            count++; 
        }
    }

    cout << "So dong xu can tra lai la: ";
    cout << count; 
    return 0; 
}