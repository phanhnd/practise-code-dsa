#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;
int c[20][20];
int dp[1 << 20][20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    int FULL = (1 << n);

    for(int mask = 0; mask < FULL; mask++)
        for(int i = 0; i < n; i++)
            dp[mask][i] = INF;

    dp[1][0] = 0;

    for(int mask = 1; mask < FULL; mask++){
        for(int i = 0; i < n; i++){
            if(!(mask & (1 << i))) continue;
            if(dp[mask][i] == INF) continue;

            for(int j = 0; j < n; j++){
                if(mask & (1 << j)) continue;
                int newMask = mask | (1 << j);
                dp[newMask][j] = min(dp[newMask][j], dp[mask][i] + c[i][j]);
            }
        }
    }

    int res = INF;
    for(int i = 1; i < n; i++){
        res = min(res, dp[FULL - 1][i] + c[i][0]);
    }

    cout << res << "\n";
    return 0;
}
