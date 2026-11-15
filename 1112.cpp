#include <bits/stdc++.h> 
using namespace std; 

//Kiem tra xem mot o co o bien khong 
bool check(int curRow, int curCol, int row, int col){
    if(curRow == 0 || curRow == row || curCol == 0 || curCol == col) return true; 
    else return false;
}

int main(){
    int n, m, r, c; 
    cin >> n >> m >> r >> c; 
    r--; 
    c--
    int matrix[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j+=) {
            cin >> matrix[i][j];
        }
    }

    int used[n][m]; //danh so o da ghe
    int dx[4] = { 0, 0, 1, -1};
    int dy[4] = { 1, -1, 0, 0};

    if(matrix[r][c] == 1){
        cout << -1 << endl; 
    }
}