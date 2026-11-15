#include <bits/stdc++.h> 
using namespace std; 

int m, n; 
vector<int> teacher_can; 
vector<int> conflict_mask; 
vector<vector<int>> eligible; 
vector<int> order; 
vector<int> teacher_mask; 
vector<int> loadt; 
int limitL;

bool dfs(int pos){
    if(pos == n) return true; 
    int c = order[pos];
    for(int t : eligible[c]){
        if(loadt[t] < limitL && (teacher_mask[t] & conflict_mask[c]) == 0){
            teacher_mask[t] |= (1 << c);
            loadt[t]++;
            if(dfs(pos + 1)) return true; 
            loadt[t]--; 
            teacher_mask[t] &= ~(1 << c);
        }
    }
    return false; 
}

bool feasible(int L){
    limitL = L;
    teacher_mask.assign(m, 0);
    loadt.assign(m, 0);
    return dfs(0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n; 
    teacher_can.assign(m, 0);

    for(int i = 0; i < m; i++){
        int k; 
        cin >> k; 
        for(int j = 0; j < k; j++){
            int c; 
            cin >> c;
            c--; 
            teacher_can[i] |= (1 << c);
        }
    }

    int k; 
    cin >> k; 
    conflict_mask.assign(n, 0);
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b; 
        a--, b--; 
        conflict_mask[a] |= (1 << b);
        conflict_mask[b] |= (1 << a);
    }

    eligible.assign(n, {});
    for(int c = 0; c < n; c++){
        for(int t = 0; t < m; t++){
            if(teacher_can[t] & (1 << c)) eligible[c].push_back(t);
        }
    }

    for(int c = 0; c < n; c++){
        if(eligible[c].empty()){
            cout << -1 << "\n";
            return 0; 
        }
    }

    order.resize(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b){
        return eligible[a].size() < eligible[b].size();
    });

    int lo = 1, hi = n, ans = -1; 
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(feasible(mid)){
            ans = mid; 
            hi = mid - 1; 
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0; 
}