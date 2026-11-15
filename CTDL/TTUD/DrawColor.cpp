#include <bits/stdc++.h> 
using namespace std; 

int V, M; 
vector<vector<int>> adj; 
vector<int> colors; 

bool safeColor(int node, int color){
    for(int neighbor : adj[node]){
        if(colors[neighbor] == color) return false;
    }
    return true; 
}

bool backtrack(int node){
    if(node == V) return true; 

    for(int c = 1; c <= M; c++){
        if(safeColor(node, c)){
            colors[node] = c;
            if(backtrack(node + 1)) return true; 
            colors[node] = 0;
        }
    }
    return false; 
}

int main(){
    cin >> V >> M; 
    adj.assign(V, {});
    colors.assign(V, 0);

    int u, v, E; 
    cin >> E; 
    while(E--){
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(backtrack(0)){
        cout << "Ket qua to mau la:\n";
        for(int i = 0; i < V; i++) {
            cout << "Dinh " << i << " = mau " << colors[i] << endl;  
        }
    } else {
        cout << "Khong the to mau";
    }
    return 0; 
}