#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, W;
    cin >> N >> W;

    vector<int> weight(N+1), value(N + 1);
    for(int i = 1; i <= N; i++) cin >> weight[i];
    for(int i = 1; i <= N; i++) cin >> value[i];

    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for(int i = 1; i <= N; i++) {
        for(int w = 1; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            if(weight[i] <= w){
                dp[i][w] = max(dp[i][w], dp[i-1[w-weight[i]] + value[i]);
            }
        }
    }

    cout << dp[N][W];
    return 0;
}
