#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> combination;

void backtrack(int start, int cnt){
    if(cnt == K) {
        for(int x : combination) cout << x << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i <= N - (K - cnt) + 1; i++) {
        combination.push_back(i);
        backtrack(i + 1, cnt + 1);
        combination.pop_back();
    }
}

int main(){
    cin >> N >> K;
    backtrack(1, 0);
    return 0;
}
