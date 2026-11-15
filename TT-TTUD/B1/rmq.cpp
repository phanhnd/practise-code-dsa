#include <bits/stdc++.h> 
using namespace std; 

const int MAXN = 1e6 + 5; 
const int LOG = 21; 

int n, m; 
int a[MAXN];
int M[MAXN][LOG];
int lg[MAXN];

void buildMatrix(){
    lg[1] = 0; 
    for(int i = 2; i <= n; i++) {
        lg[i] = lg[i/2] + 1; 
    }
    for(int i = 0; i < n; i++){
        M[i][0] = i;
    }

    for(int j = 1; (1 << j) <= n; j++){
        for(int i = 0; i + (1<<j) <= n; i++) {
            int left = M[i][j - 1];
            int right = M[i + (1 << (j-1))][j-1];
            if(a[left] < a[right]) M[i][j] = left; 
        }
    }
}

int rmq(int l, int r){
    int len = r - l + 1; 
    int j = lg[len];
    int left = M[l][j];
    int right = M[r - (1 << j) + 1][j];
    return min(a[left], a[right]);
}

int main(){
    cin >> n; 
    for(int i = 0; i < n; i++) cin >> a[i];

    buildMatrix();

    cin >> m; 
    long long sum = 0; 
    for(int i = 0; i < m; i++){
        int l, r; 
        cin >> l >> r; 
        sum += rmq(l,r);
    }
    cout << sum << "\n";
    return 0; 
}