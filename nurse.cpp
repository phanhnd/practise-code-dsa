#include <bits/stdc++.h> 
using namespace std; 

const int N = 1003; 
int n, K1, K2; 
int S0[N], S1[N];

int main(){
    cin >> n >> K1 >> K2; 
    S0[1] = S1[K1] = S0[0] = 1; 
    for(int i = K1 + 1; i <= n; i++){
        S0[i] = S1[i-1];
        for(int j = K1; j <= K2 && j <= i; j++){
            S1[i] += S0[i-j];
        }
    }
    cout << S0[n] + S1[n];
    return 0; 
}
