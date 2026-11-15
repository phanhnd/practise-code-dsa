#include <iostream> 
#include <vector> 
#include <unordered_map> 
#include <queue> 
using namespace std; 

vector<int> topKFrequent(vector<int>& nums, int k){
    //step 1: count frequency
    unordered_map<int, int> freq; 
    for(int num: nums){
        freq[num]++;
    }

    //Step 2: Use min-heap (priority_queue with custom comparator)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;


    for (auto& it : freq){
        int num = it.first; 
        int count = it.second; 
        minHeap.push({count, num});
        if((int)minHeap.size() > k){
            minHeap.pop();
        }
    }

    //step 3: Extract top k frequent alements
    vector<int> result; 
    while(!minHeap.empty()){
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result; 
}

int main(){
    vector<int> nums = { 1, 1, 1, 2, 2, 3};
    int k = 2; 

    vector<int> ans = topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for(int x : ans) cout << x << " ";
    cout << endl; 
    
    return 0; 
}