#include <bits/stdc++.h> 
using namespace std; 

int H, W, n; 
vector<pair<int, int>> rect; 
int grid[11][11];

bool placeRect(int d, int n, int h, int w, int val){
    if(d + h > H || n + w > W) return false; 

    for(int i = d; i < d + h; i++){
        for(int j = n; j < n + w; j++){
            if(grid[i][j] != 0 && val == 1) return false;  
        }
    }

    for(int i = d; i < d + h; i++){
        for(int j = n; j < n + w; j++) {
            grid[i][j] = val;
        }
    }
    return true; 
}

bool backtrack(int idx){
    if(idx == n) return true; 
    int h = rect[idx].first;
    int w = rect[idx].second;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(placeRect(i, j, h, w, 1)){
                if(backtrack(idx + 1)) return true; 
                placeRect(i, j, h, w, 0);
            }

            if(placeRect(i, j, w, h, 1)){
                if(backtrack(idx + 1)) return true; 
                placeRect(i, j, w, h, 0);
            }
        }
    }
    return false;
}

int main(){
    cin >> H >> W >> n; 
    rect.resize(n);
    for(int i = 0; i < n; i++) cin >> rect[i].first >> rect[i].second; 
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            grid[i][j] = 0; 
        }
    }
    if(backtrack(0)) cout << 1;
    else cout << 0; 
    return 0; 
}