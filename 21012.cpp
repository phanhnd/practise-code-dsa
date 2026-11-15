#include <bits/stdc++.h> 
using namespace std; 

struct Point {
    int x, y; 
};

int main(){
    int n, m, r, c; 
    cin >> n >> m >> r >> c; 
    r--; 
    c--; 

    vector<vector<int>> maze(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    //kiem tra neu o xuat phat la tuong 
    if(maze[r][c] == 1) {
        cout << -1 << endl; 
        return 0; 
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<Point> q; 

    dist[r][c] = 0; 
    q.push({r, c});

    int dx[4] = { -1, 1, 0, 0};
    int dy[4] = { 0, 0, -1, 1};

    while(!q.empty()){
        Point p = q.front();
        q.pop();

        if(p.x == 0 || p.x == n - 1 || p.y == 0 || p.y == m - 1){
            result = dist[p.x][p.y] + 1; 
            break; 
        }

        for(int i = 0; i < 4; i++){
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if(nx >= x && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[p.x][p.y] + 1; 
                q.push({ nx, ny });
            }
        }
    }

    cout << result << endl; 
    return 0; 
}