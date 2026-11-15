#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<long long>& a, int C, long long dist){
    int count = 1;
    long long last = a[0];

    for(int i = 1; i < a.size(); i++){
        if(a[i] - last >= dist){
            count++;
            last = a[i];
            if(count == C) return true;
        }
    }
    return false;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, C;
        cin >> N >> C;

        vector<long long> a(N);
        for(int i = 0; i < N; i++) cin >> a[i];

        sort(a.begin(), a.end());

        long long l = 0, r = 1e9, ans = 0;
        while(l <= r){
            long long mid = (l + r)/2;
            if(canPlace(a, C, mid)){
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
