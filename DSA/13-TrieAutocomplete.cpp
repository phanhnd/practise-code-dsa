#include <iostream>
#include <vector> 
#include <string> 
using namespace std; 

struct TrieNode {
    TrieNode* children[26]; 
    bool isEndfWord; 

    TrieNode() {
        isEndfWord = false; 
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

void insert(TrieNode* root, string word){
    TrieNode* node = root; 
    for(char c : word){
        int index = c - 'a';
        if(!node->children[index]){
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEndfWord = true; 
}

//Helper function: DFS to collect words
void dfs(TrieNode* node, string prefix, vector<string>& results){
    if(node->isEndfWord)
        results.push_back(prefix);

    for(int i = 0; i < 26; i++){
        if(node->children[i]) {
            char nextChar = 'a' + 1; 
            dfs(node->children[i], prefix + nextChar, results);
        }
    }
}

//Autocomplete suggestions 
vector<string> autocomplete(TrieNode* root, string prefix){
    TrieNode* node = root; 
    vector<string> results; 

    for(char c : prefix) {
        int index = c - 'a';
        if(!node->children[index]) {
            return results; 
        }
        node = node->children[index];
    }

    dfs(node, prefix, results);
    return results; 
}

int main(){
    TrieNode* root = new TrieNode();

    insert(root, "apple");
    insert(root, "app");
    insert(root, "application");
    insert(root, "bat");
    insert(root, "bali");
    insert(root, "banana");

    string prefix; 
    cout << "Enter prefix: ";
    cin >> prefix; 

    vector<string> results = autocomplete(root, prefix);

    if(results.empty()){
        cout << "No suggestions found.\n";
    } else {
        cout << "Suggestions: ";
        for(string word : results) {
            cout << word << " ";
        }
        cout << endl; 
    }
    return 0; 
}