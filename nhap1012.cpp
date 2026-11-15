#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> a;
vector<vector<int>> groupMem;
vector<int> groupSum;
int targetSum;

bool backtrack(int idx) {
    if (idx == N) {
        for (int i = 0; i < K; i++)
            if (groupSum[i] != targetSum) return false;
        return true;
    }

    for (int i = 0; i < K; i++) {

        // nhánh cận
        if (groupSum[i] + a[idx] > targetSum) continue;

        // gán element vào group i
        groupSum[i] += a[idx];
        groupMem[i].push_back(a[idx]);

        if (backtrack(idx + 1)) return true;

        // hoàn tác
        groupSum[i] -= a[idx];
        groupMem[i].pop_back();

        // tối ưu: nếu group đang rỗng -> không thử group rỗng tiếp theo
        if (groupSum[i] == 0) break;
    }

    return false;
}

int main() {
    cin >> N >> K;
    a.resize(N);

    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % K != 0) {
        cout << "NO\n";
        return 0;
    }

    targetSum = sum / K;

    sort(a.begin(), a.end(), greater<int>());

    if (a[0] > targetSum) {
        cout << "NO\n";
        return 0;
    }

    groupMem.assign(K, vector<int>());
    groupSum.assign(K, 0);

    if (backtrack(0)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
