#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> c;
int chiphi = 0;
int best = INT_MAX;
vector<bool> works;
int minphi = INT_MAX;

void backtrack(int k){
    if(k == n){
        best = min(best, chiphi);
        return;
    }

    for(int i = 0; i < n; i++){
        if(!works[i]){
            if(chiphi + works[i] + (n - i) * minphi > best) break;
            works[i] = true;
            chiphi += c[k][i];
            backtrack(k + 1);

            works[i] = false;
            chiphi -= c[k][i];
        }
    }
}


int main(){
    cin >> n;
    c.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            cin >> c[i][j];
            minphi = min(minphi, c[i][j]);
        }
    }

    works.resize(n, false);
    backtrack(0);
    cout << best << endl;
    return 0;
}
