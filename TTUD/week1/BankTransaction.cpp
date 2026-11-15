#include <bits/stdc++.h> 
using namespace std; 

struct Transaction {
    string from, to; 
    int money; 
};

vector<Transaction> transaction; 
set<string> accounts; 
unordered_map<string, vector<string>> graph; 

//dfs to check cycle of length k 
bool dfs(const string& start, const string& current, int depth, int k, unordered_set<string> &visited){
    if(depth == k){
        return current == start; 
    }

    if(!graph.count(current)) return false; 

    for(auto &neighbor : graph[current]){
        if(visited.count(neighbor)) continue; 
        visited.insert(neighbor);
        if(dfs(start, neighbor, depth + 1, k, visited)) return true; 
        visited.erase(neighbor);
    }
    return false; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //READ data block
    while(true){
        string line; 
        if(!getline(cin, line)) break;
        if(line == "#") break; 
        if(line.empty()) continue; 

        string from, to, time_point, atm; 
        int money; 
        stringstream ss(line);
        ss >> from >> to >> money >> time_point >> atm; 

        transaction.push_back({from, to, money});
        accounts.insert(from);
        accounts.insert(to);
        graph[from].push_back(to);
    }

    //process query block
    while(true){
        string query;
        if(!getline(cin, query)) break; 
        if(query == "#") break; 
        if(query.empty()) continue; 
        

        stringstream ss(query);
        string cmd; 
        ss >> cmd; 

        if(cmd == "?number_transactions"){
            cout << transaction.size() << "\n";
        }
        else if (cmd == "?total_money_transaction"){
            long long total = 0; 
            for(auto &tr : transaction) total += tr.money; 
        }
        else if (cmd == "?total_money_transaction"){
            vector<string> acc(accounts.begin(), accounts.end());
            sort(acc.begin(), acc.end());
            for(int i = 0; i < (int)accounts.size(); i++){
                if(i) cout << " ";
                cout << acc[i];
            }
            cout << "\n";
        }
        else if (cmd == "?total_money_transaction_from"){
            string acc; 
            ss >> acc; 
            long long total = 0; 
            for(auto &tr : transaction){
                if(tr.from == acc) total += tr.money;
            }
            cout << total << "\n";
        }
        else if (cmd == "?inspect_cycle"){
            string start; 
            int k; 
            ss >> start >> k; 
            unordered_set<string> visited; 
            visited.insert(start);
            cout << (dfs(start, start, 0, k, visited) ? 1 : 0) << "\n";
        }
    }
    return 0; 
}