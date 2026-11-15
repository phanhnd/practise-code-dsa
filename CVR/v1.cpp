#include <bits/stdc++.h> 
using namespace std; 

int n, K, Q; 
int d[13], c[13][13];
int minC = INT_MAX; 

vector<int> delivery; 
int soXeDaDung = 1; 
int soHangHienTaiTrenXe; 
int best = INT_MAX; 
int chiphi = 0;

stack<int> curPos; 

void CVR(int delivered){
    int remain = n - delivered;
    if(chiphi + (remain + 1) * minC >= best) return; 

    if(delivered == n) {
        chiphi += c[curPos.top()][0];
        best = min(best, chiphi);
        chiphi -= c[curPos.top()][0];
        return; 
    }

    int first = -1; 
    for(int i = 1; i <= n; i++) {
        if(!delivery[i]) {
            first = i;
            break; 
        }
    }

    for(int i = 1; i <= n; i++){
        if(!delivery[i] && soHangHienTaiTrenXe >= d[i]) {
            if(i != first) continue; 

            delivery[i] = 1; 
            soHangHienTaiTrenXe -= d[i];

            int phi = c[curPos.top()][i];
            chiphi += phi; 
            curPos.push(i);

            CVR(delivered + 1);
            chiphi -= phi; 
            soHangHienTaiTrenXe += d[i];
            delivery[i] = 0; 
        }
    }

    if(soXeDaDung < K && curPos.top() != 0){
        int back = c[curPos.top()][0];
        chiphi += back; 

        curPos.pop();
        curPos.push(0);

        soXeDaDung++; 
        int oldLoad = soHangHienTaiTrenXe;
        soHangHienTaiTrenXe = Q; 

        CVR(delivered);

        soHangHienTaiTrenXe = oldLoad; 
        soXeDaDung--; 

        curPos.pop();
        curPos.push(0);

        chiphi -= back;
    }
}

int main(){
    cin >> n >> K >> Q; 
    for(int i = 1; i <= n; i++) cin >> d[i];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if(i != j) minC = min(minC, c[i][j]);
        }
    }

    delivery.assign(n + 1, 0);
    soHangHienTaiTrenXe = Q; 
    curPos.push(0);

    CVR(0);

    cout << best; 
    return 0; 
}