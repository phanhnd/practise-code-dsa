#include <bits/stdc++.h> 
using namespace std; 

void bfs(int start, vector<vector<int>>& adj){
    vector<int> visited(adj.size(), false);
    queue<int> q; 

    visited[start] = true; 
    q.push(start);

    while(!q.empty()){
        int u = q.front(); 
        q.pop();
        cout << u << " ";

        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true; 
                q.push(v);
            }
        }
    }
}

int main(){
    vector<vector<int>> adj(5);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0};
    adj[3] = {1, 4};
    adj[4] = {3};

    cout << "BFS Traversal: ";
    bfs(0, adj);
    return 0; 
}