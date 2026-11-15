#include <bits/stdc++.h> 
using namespace std; 

struct Item{
    int weight, value; 
    double ratio; 
};

int W;
int maxValue = 0;
vector<Item> items; 
vector<Item> bag;
int wBag = 0; 
int vBag = 0;
int max_lower_bound = 0; 

int lower_bound(int node){
    int n = items.size();
    int lower_bound = vBag; 
    for(int i = node; i < n; i++){
        lower_bound = items[i].ratio * (W - wBag);
    }
    return lower_bound; 
}

int solve(int node, vector<Item>& item, vector<Item>& bag){
    if()
}