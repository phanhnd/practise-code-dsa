#include <bits/stdc++.h> 
using namespace std; 

struct activity {
    string id; 
    int start, end, profit; 
};

bool compareEnd(activity a, activity b) {
    return a.end > b.end;
}

void solutionActivity(vector<activity>& activitys){
    sort(activitys.begin(), activitys.end(), compareEnd);

    for(auto& act : activitys){
        
    }
}
