#include <bits/stdc++.h> 
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<int> a(n);
    for(int &x : a) cin >> x; 
    
    long long ans = 0; 
    while(a.size() > 1){
        int k = a.size();
        int phimax = 0; 
        vector<int> b; 
        for(int i = 0; i + 1 < k; i += 2){
            int merged = a[i] + a[i + 1];
            phimax = max(phimax, merged);
            b.push_back(merged);
        }

        if(k % 2 == 1) b.push_back(a.back());

        ans += phimax; 
        a = b; 
    }

    cout << ans; 
}