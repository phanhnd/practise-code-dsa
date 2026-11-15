#include <iostream> 
using namespace std; 

struct Node {
    int val; 
    Node* left; 
    Node* right; 

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val){
    if(!root) return new Node(val);
    if(val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root; 
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){
    Node* root = nullptr; 
    root = insert(root, 5);
    insert(root, 2);
    insert(root, 8);
    insert(root, 7);
    inorder(root);
    return 0; 
}

