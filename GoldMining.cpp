#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, L1, L2;
    cin >> n >> L1 >> L2;

    vector<int> a(n + 1), F(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    priority_queue<pair<int,int>> pq;
    int ans = INT_MIN;

    for(int i = 1; i <= n; i++){
        F[i] = a[i];

        if(i - L1 >= 1)
            pq.push({F[i - L1], i - L1});

        while(!pq.empty() && pq.top().second < i - L2)
            pq.pop();
            
        if(!pq.empty())
            F[i] = a[i] + pq.top().first;

        ans = max(ans, F[i]);
    }

    cout << ans;
}
