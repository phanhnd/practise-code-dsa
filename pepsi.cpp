#include <bits/stdc++.h> 
using namespace std; 

int n, K, Q; 
int d[13];
int c[13][13];

bool visited[13];
int load[6];
int curPos[6];


int best = INT_MAX; 
int curDist = 0; 

void backtrack(int k, int served){
    if(served == n){
        int total = curDist; 
        for(int i = 1; i <= K; i++){
            total += c[curPos[i]][0];
        }
        best = min(best, total);
        return; 
    }

    if(k > K) return; 

    for(int i = 1; i <= n; i++){
        if(!visited[i] && load[k] + d[i] <= Q) {
            visited[i] = true;
            load[k] += d[i];

            int prev = curPos[k];
            curPos[k] = i; 
            curDist += c[prev][i];

            if(curDist < best) backtrack(k, served + 1);

            curDist -= c[prev][i];
            curPos[k] = prev;
            load[k] -= d[i];
            visited[i] = false; 
        }
    }

    //ket thuc xe k
    int backCost = c[curPos[k]][0];
    curDist += backCost; 

    if(curDist < best) backtrack(k + 1, served);

    curDist -= backCost; 
}

int main(){
    cin >> n >> K >> Q; 
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    for(int i = 1; i <= K; i++) curPos[i] = 0; 

    backtrack(1, 0);
    cout << best << endl; 
}