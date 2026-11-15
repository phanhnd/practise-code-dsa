#include <bits/stdc++.h>
using namespace std;

int n, K;
vector<vector<int>> d;
vector<bool> picked, delivered;
int load = 0;
int best = INT_MAX;
int curCost = 0;
vector<int> route;

int minEdge = 1e9;

void backtrack(int count){
    if(curCost + (2*n - count) * minEdge >= best) return;

    if(count == 2*n) {
        int last = route.back();
        best = min(best, curCost + d[last][0]);
        return;
    }

    int last = route.back();

    for(int i = 1; i <= n; i++) {
        if(!picked[i] && load < K) {
            picked[i] = true;
            load++;

            curCost += d[last][i];
            route.push_back(i);

            backtrack(count + 1);

            route.pop_back();
            curCost -= d[last][i];

            load--;
            picked[i] = false;
        }
    }

    for(int i = 1; i <= n; i++){
        if(picked[i] && !delivered[i]) {
            int drop = i + n;
            delivered[i] = true;
            load--;

            curCost += d[last][drop];
            route.push_back(drop);

            backtrack(count + 1);

            route.pop_back();
            curCost -= d[last][drop];

            load++;
            delivered[i] = false;
        }
    }
}

int main(){
    cin >> n >> K;

    d.resize(2*n + 1, vector<int>(2*n + 1));
    picked.assign(n + 1, false);
    delivered.assign(n + 1, false);

    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++) {
            cin >> d[i][j];
            if(i != j) minEdge = min(minEdge, d[i][j]);
        }
    }

    route.push_back(0);
    backtrack(0);

    cout << best << endl;
}
