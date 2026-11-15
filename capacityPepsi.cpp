#include <bits/stdc++.h> 
using namespace std; 

int n, K, Q; 
int d[13];
int c[13][13];
vector<bool> visited; 
int hangTrenXe = Q; 
int best = INT_MAX;
int dis = 0; 
int usedXe = 1; 
int curPos = 0; 

void solve(int y){
    if(y > n){
        best = min(best, dis); 
        return; 
    } 
    for(int i = 1; i <= n; i++){
        if(!visited[i] && hangTrenXe >= d[i]){
            visited[i] = true; 
            hangTrenXe -= d[i];
            int s = c[curPos][i];
            int cur = curPos;
            curPos = i;
            dis += s;
            solve(y + 1);
            
            visited[i] = false; 
            hangTrenXe += d[i];
            dis -= s;
            curPos = cur; 
        }
    }

    //quay ve 
    if(usedXe <= K){
        usedXe++; 
        dis += c[curPos][0];
        int s = c[curPos][0];
        curPos = 0; 
        hangTrenXe = Q; 
    }
}

int main(){
    cin >> n >> K >> Q; 
    memset(d, 0, (n + 1) * sizeof(int));
    memset(c, 0, sizeof(c));
    visited.resize(n +1 , false);
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cin >> c[i][j];
        }
    }
    solve(1);
    cout << best << "\n";
    return 0; 
}