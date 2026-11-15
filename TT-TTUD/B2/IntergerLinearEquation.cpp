#include<bits/stdc++.h> 
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    long long M; 
    if(!(cin >> n >> M)) return 0; 
    vector<int> a(n);
    long long sumA = 0; 
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sumA += a[i];
    }

    long long Mprime = M - sumA;
    if(Mprime < 0){
        cout << 0 << "\n";
        return 0; 
    }

    int T = (int)Mprime; 
    vector<unsigned long long> dp(T + 1);
    dp[0] = 1; 
    for(int i = 0; i < n; ++i){
        int w = a[i];
        for(int j = w; j <= T; ++j){
            dp[j] += dp[j - w];
        }
    }

    cout << dp[T] << "\n";
    return 0; 
}