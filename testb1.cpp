#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> arr;
map<int, vector<int>> group;
int countGroup = 0;
int curSum = 0;

bool backtrack(int k, int SUM){
    if(countGroup == K) return true;

    if(arr[k] + curSum == SUM){
        group[countGroup].push_back(arr[k]);
        curSum = 0;
        countGroup++;
        backtrack(k + 1, SUM);

        curSum = SUM - arr[k];
        countGroup--;
        group[countGroup].pop_back();
    }

    if (arr[k] + curSum < SUM) {
        group[countGroup].push_back(arr[k]);
        curSum += arr[k];
        backtrack(k + 1, SUM);

        curSum -= arr[k];
        group[countGroup].pop_back();
    }

    backtrack(k + 1, SUM);
    return false;
}

int main(){
    cin >> N >> K;
    arr.resize(N);
    int sumAll = 0;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        sumAll += arr[i];
    }


    if(sumAll % K == 0){
        int SUM = sumAll / K;
        if(backtrack(0, SUM)) cout << "YES\n";
        else cout << "NO\n";
    } else {
        cout << "NO\n";
    }
}
