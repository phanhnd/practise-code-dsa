#include <bits/stdc++.h> 
using namespace std; 

int n, K, Q; 
int w[13], c[13][13];
int best = INT_MAX; 
bool used[13];
int minC= INT_MAX; 

void try(int cur, int cost, int load, int soKhachDaGiao, int soNhanVienDaDung){
    if(cost >= best) return; 
    if(soKhachDaGiao == n){
        best = min(best, cost + c[cur][0]);
        return; 
    }

    if(soNhanVienDaDung > K) return; 

    int soKhachChuaGiao = n - soKhachDaGiao; 
    if(cost + (soKhachChuaGiao + 1) * minC >= best) return; 

    int first = -1; 
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            first = i; 
            break; 
        } 
    }

    for(int i = 1; i <= n; i++){
        if(!used[i] && load >= w[i]){
            if(cur != 0 && i != first) continue; 

            used[i] = true; 
            try(i, cost + c[cur][i], load - w[i], soKhachDaGiao + 1, soNhanVienDaDung);
        }
    }

    if(cur != 0){
        try(0, cost + c[cur][0], Q, soKhachDaGiao, soNhanVienDaDung + 1);
    }
}

int main(){
    cin >> n >> Q >> K; 
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if(i != j) minC = min(minC, c[i][j]);
        }
    }

    memset(used, false, sizeof(used));
    try(0, 0, Q, 0, 1);
    cout << best << endl; 
    return 0; 
}