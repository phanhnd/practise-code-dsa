#include <bits/stdc++.h> 
using namespace std; 

int n, k; 
int c[25][25];
int dp[1 << 22][22];
int INF = 1e9; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k; 
    int m = 2 * n; 

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= m; j++){
            cin >> c[i][j];
        }
    }

    int fullMask = (1 << m);
    for(int mask = 0; mask < fullMask; mask++){
        for(int last = 0; last < m; last++){
            dp[mask][last] = INF;
        }
    }

    //Duyet tat ca cac trang thai
    for(int mask = 0; mask < fullMask; mask++){
        int pickups = 0, dropoffs = 0; 
        for(int i = 0; i < n; i++) if(mask & (1 << i)) pickups++; 
        for(int i = n; i < 2 * n; i++) if(mask & (1 << i)) dropoffs++;
        int onboard = pickups - dropoffs; 

        for(int last = 0; last < m; last++){
            if(dp[mask][last] == INF) continue; 

            for(int next = 0; next < m; next++) {
                if(mask & (1 << next)) continue;

                if(next >= n){
                    int pick = next - n; 
                    if(!(mask & (1 << pick))) continue;
                } else {
                    if(onboard > k) continue; 
                }

                int newMask = mask | (1 << next);
                int newCost = dp[mask][last] + c[last + 1][next + 1];
                dp[newMask][next] = min(dp[newMask][next], newCost);
            }
        }
    }

    int ans = INF;
    int finalMask = fullMask - 1; 
    
    for(int last = 0; last < m; last++){
        if(dp[finalMask][last] == INF) continue; 
        ans = min(ans, dp[finalMask][last] + c[last + 1][0]);
    }

    cout << ans << "\n";
    return 0; 
}