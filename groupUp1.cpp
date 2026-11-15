#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<int> a;

void backtrack(int k){
    if(k == 1) return;
    int phimax = 0;
    if(k % 2 == 1){
        for(int i = 0; i < k/2; i++){
            a[i] = a[2 * i] + a[2 * i + 1];
            phimax = max(phimax, a[i]);
        }
        a[k/2] = a[k - 1];
    } else {
        for(int i = 0; i < k; i++){
            a[i] = a[2 * i] + a[2 * i + 1];
            phimax = max(phimax, a[i]);
        }
    }
    ans += phimax;
    backtrack(k/2 + 1);
}

int main(){
    int n; cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    backtrack(n);
    cout << ans;
}
