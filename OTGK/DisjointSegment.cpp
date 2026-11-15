#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int MAX = 1000000;
    vector<vector<Segment>> bucket(MAX + 1);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        bucket[b].push_back({a, b});
    }

    int count = 0;
    int last_end = -1;

    for (int b = 0; b <= MAX; b++) {
        for (auto &seg : bucket[b]) {
            if (seg.a > last_end) {
                count++;
                last_end = seg.b;
            }
        }
    }

    cout << count;
    return 0;
}
