#include <bits/stdc++.h> 
using namespace std; 

int n, K; 
int c[23][23];
int best = INT_MAX; 
bool daDon[12];
bool daTra[12];
int minC = INT_MAX;

void backtrack(int viTriHienTai, int soKhachTrenXe, int chiPhi, int soKhachDaDon, int soKhachDaTra){
    if(soKhachDaTra == n){
        best = min(best, chiPhi + c[viTriHienTai][0]);
        return;
    }

    int soDiemDaGhe = soKhachDaDon + soKhachDaTra;
    int soDiemConLai = 2*n - soDiemDaGhe; 
    if((soDiemConLai + 1)*minC + chiPhi >= best) return; 

    for(int i = 1; i <= n; i++){
        if(!daDon[i]){
            if(soKhachTrenXe < K) {
                //don i
                daDon[i] = true; 
                backtrack(i, soKhachTrenXe + 1, chiPhi + c[viTriHienTai][i], soKhachDaDon + 1, soKhachDaTra);

                daDon[i] = false; 
            }
        }

        if(daDon[i] && !daTra[i]) {
            daTra[i] = true; 
            backtrack(i + n, soKhachTrenXe - 1, chiPhi + c[viTriHienTai][i + n], soKhachDaDon, soKhachDaTra + 1);

            daTra[i] = false;
        } 
    }
}

int main(){
    cin >> n >> K;  
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++) {
            cin >> c[i][j];
            if(i != j) minC = min(minC, c[i][j]);
        }
    }

    memset(daDon, false, sizeof(daDon));
    memset(daTra, false, sizeof(daTra));
    backtrack(0, 0, 0, 0, 0);
    cout << best; 
    return 0; 
}