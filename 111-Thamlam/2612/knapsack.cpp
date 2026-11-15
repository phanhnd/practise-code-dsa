#include <bits/stdc++.h> 
using namespace std;

struct Item {
    int weight; 
    int value; 
    double ratio; 
};

bool cmp(Item a, Item b){
    return a.ratio > b.ratio;
}

int n, W; 
vector<Item> items; 
int bestValue = 0; 

//tinh can tren
double bound(int level, int curWeight, int curValue){
    if(curWeight >= W) return 0; 

    double result = curValue; 
    double totalWeight = curWeight; 

    for(int i = level; i < n; i++){
        if(totalWeight + items[i].weight <= W){
            totalWeight += items[i].weight; 
            result += items[i].value; 
        } else {
            int remain = W - totalWeight; 
            result += items[i].ratio * remain; 
        }
    }
    return result; 
}

//Ham quay lui + nhanh can
void brandAndBound(int level, int curWeight, int curValue){
    if(curValue > bestValue) bestValue = curValue; 

    if(level == n) return; 

    double ub = bound(level, curWeight, curValue);

    if(ub <= bestValue) return; 

    //nhanh 1: chon do vat 
    if(curWeight + items[level].weight <= W){
        brandAndBound(level + 1, curWeight + items[level].weight, curValue + items[level].value);
    }

    //Nhanh 2: khong chon do vat 
    brandAndBound(level + 1, curWeight, curValue);
}


int main(){
    n = 4; 
    W = 8; 

    items = {
        {2, 40, 0},
        {3, 50, 0},
        {5, 100, 0},
        {4, 60, 0}
    };

    for(auto &it : items){
        it.ratio = (double)it.value / it.weight; 
    }

    sort(items.begin(), items.end(), cmp);

    brandAndBound(0, 0, 0);
    cout << "Max Value: " << bestValue << "\n";
    return 0; 
}