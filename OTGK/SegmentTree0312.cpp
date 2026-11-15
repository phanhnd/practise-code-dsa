#include <bits/stdc++.h> 
using namespace std; 

const int MAXN = 200000; 
int st[4 * MAXN];

void build(vector<int> &a, int id, int l, int r){
    if(l == r){
        st[id] = a[l];
        return;
    }

    int mid = (l + r)/2;
    build(a, id*2, 1, mid);
    build(a, id*2 + 1, mid+1, r);
    st[id] = max(st[id*2], st[id*2 + 1]);
}

void update(int id, int l, int r, int pos, int val){
    if(l == r){
        st[id] = val; 
    }

    int mid = (l + r)/2;
    if(pos <= mid) update(id*2, 1, mid, pos, val);
    else update(id*2 + 1, mid+1, r, pos, val);

    st[id] = max(st[id*2], st[id*2 + 1]);
}

int query(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0; 
    if(u <= l && r <= v) return st[id];
    int mid = (l + r)/2;
    return max(query(id*2, 1, mid, u, v), query(id*2 + 1, mid + 1, r, u, v));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    build(a, 1, 1, n);
    
    int m; 
    cin >> m; 
    cin .ignore(numeric_limits<streamsize>::max(), '\n');

    while(m--){
        string line, cmd; 
        int x, y; 
        
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd >> x >> y;

        if(cmd == "get-max"){
            cout << query(1, 1, n, x, y) << "\n";
        } else if (cmd == "update"){
            update(1, 1, n, x, y);
        }
    }
    return 0; 
}