#include <bits/stdc++.h> 
using namespace std; 

int H, W, n; 
vector<pair<int, int>> rects; 
int grid[11][11];

bool canPlace(int r, int c, int h, int w){
    if(r + h > H || c + w > W) return false; 
    for(int i = r; i < r + h; ++i) {
        for(int j = c; j < c + w; ++j) {
            if(grid[i][j]) return false; 
        }
    }
    return true; 
}

void place(int r, int c, int h, int w, int val){
    for(int i = r; i < r + h; ++i){
        for(int j = c; j < c + w; ++j) {
            grid[i][j] = val; 
        }
    }
}

bool solve(int idx){
    if(idx == n) return true;

    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(grid[i][j]) continue; 

            auto [h, w] = rects[idx];
            for(int rot = 0; rot < 2; ++rot) {
                if(canPlace(i, j, h, w)){
                    place(i, j, h, w, 1);
                    if(solve(idx + 1)) return true; 
                    place(i, j, h, w, 0);
                }
                swap(h, w);
            }
            return false; 
        }
    }
    return false; 
}

int main(){
    cin >> H >> W; 
    cin >> n; 
    rects.resize(n);

    int total = 0; 
    for(int i = 0; i < n; ++i){
        cin >> rects[i].first >> rects[i].second;
        total += rects[i].first * rects[i].second;
    }

    if(total != H * W) {
        cout << 0; 
        return 0; 
    }

    cout << (solve(0) ? 1 : 0);
}