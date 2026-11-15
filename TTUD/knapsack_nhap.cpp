#include <bits/stdc++.h> 
using namespace std;

struct Item {
    int id; 
    double value; 
    double weight; 
    double ratio; 
};

struct Node {
    int level;
    double profit; 
    double weight; 
    double bound; 
    vector<int> path; 
};

double caclBound(const Node &node, double W, const vector<Item> &items){
    if(node.weight >= W) return 0; 

    double bound = node.profit; 
    double totalWeight = node.weight;

    for(int i = node.level; i < (int)items.size(); i++){
        if(totalWeight + items[i].weight <= W) {
            totalWeight += items[i].weight; 
            bound += items[i].value;
        } else {
            double remain = W - totalWeight; 
            bound += items[i].value * (remain / items[i].weight);
            break;
        }
    }
    return bound; 
}

