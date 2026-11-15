#include <bits/stdc++.h> 
using namespace std; 

int n, S; 
vector<int> arr; 
vector<int> current; 
int countt = 0; 

void printSolution(vector<int>& current){
    for(int c : current) cout << c << " ";
}

void backtrack(int index, int sum){
    if(sum == S) {
        countt++; 
        cout << "Loi giai thu " << countt << " la: " << endl; 
        printSolution(current);
        cout << "\n=============\n"; 
    }

    if(index == n || sum > S) return;

    current.push_back(arr[index]);
    backtrack(index + 1, sum + arr[index]);

    current.pop_back();
    backtrack(index + 1, sum);
}

int main(){
    cin >> n >> S; 
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    backtrack(0, 0);
    if(countt == 0) cout << "NO SOLUTION\n";
    return 0; 
}