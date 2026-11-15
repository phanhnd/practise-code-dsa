#include <bits/stdc++.h> 
using namespace std; 

struct work {
    int id, deadline, profit;
};

bool compare( work a, work b){
    return a.profit > b.profit;
}

int solveJobScheduling(vector<int>& slots, vector<work>& works){
    sort(works.begin(), works.end(), compare);
    int maxProfit = 0; 
    int n = works.size();

    for(auto& work : works){
        for(int i = min(n, work.deadline) - 1; i >= 0; i--){
            if(slots[i] == -1) {
                slots[i] = work.id;
                maxProfit += work.profit; 
                break; 
            }
        }
    }
    return maxProfit; 
}

int main(){
    int n; 
    cout << "Nhap so cong viec: ";
    cin >> n; 

    vector<work> works(n);
    for(int i = 0; i < n; i++){
        cout << "Nhap deadline va loi nhuan cua cong viec thu " << i + 1 << " ";
        works[i].id = i + 1; 
        cin >> works[i].deadline >> works[i].profit;
    }

    int maxDeadline = 0; 
    for(auto& w : works) {
        maxDeadline = max(maxDeadline, w.deadline);
    }

    vector<int> slots(maxDeadline, -1);

    int maxProfit = solveJobScheduling(slots, works);
    cout << "Loi nhuan toi da thu duoc la: " << maxProfit << endl; 
    cout << "Thu tu cac cong viec duoc thuc hien la: ";
    for(int s : slots){
        if(s != -1) cout << s << " ";
    }
    return 0; 
}