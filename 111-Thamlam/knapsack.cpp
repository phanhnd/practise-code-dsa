#include <bits/stdc++.h> 
using namespace std; 

struct Item{
    double value, weight; 
};

bool compare(Item a, Item b){
    return (a.value/a.weight) > (b.value/b.weight);
}

double KnapSack(double W, vector<Item>& items){
    sort(items.begin(), items.end(), compare);
    double vBalo = 0.0; 
    double wBalo = 0.0; 

    for(Item item : items){
        if(wBalo >= W) break; 
        if(item.weight <= (W - wBalo)){
            wBalo += item.weight;
            vBalo += item.value;
        } else {
            double weight = W - wBalo; 
            double value = (weight/item.weight) * item.value;
            wBalo = W;
            vBalo += value;  
        }
    }

    return vBalo;
}

int main(){
    int n; 
    double W;
    cout << "Nhap so luong mon do: ";
    cin >> n; 
    cout << "Nhap suc chua cua balo: ";
    cin >> W; 

    vector<Item> items(n);
    for(int i = 0; i < n; i++){
        cout << "Nhap gia tri va trong luong cua mon do thu " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Trong luong max cua tui la: " << KnapSack(W, items);
    return 0; 
}