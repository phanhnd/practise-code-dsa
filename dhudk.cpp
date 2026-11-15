#include <bits/stdc++.h>
using namespace std;

struct job {
    int deadline;
    int profit;
};

bool compare(job a, job b){
    if(a.deadline > b.deadline) return true;
    else if (a.deadline == b.deadline) return a.profit > b.profit;
    return false;
}

int main(){
    int n;
    int ansProfit = 0;
    cin >> n;
    int MAXN = INT_MAX;
    vector<job> listJob(n);
    vector<bool> usedJob(MAXN, 0);
    for(int i = 0; i < n; i++){
        cin >> listJob[i].deadline >> listJob[i].profit;
    }

    sort(listJob.begin(), listJob.end(), compare);
    for(int i = listJob[n].deadline; i > 0; i--){
        if(!usedJob[i + 1] && listJob[i].deadline >= i + 1){
            usedJob[i + 1] = i + 1;
            ansProfit += listJob[i].profit;
        }
    }

    cout << ansProfit << endl;
    return 0;
}
