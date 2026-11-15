#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data; 
    Node* left; 
    Node* right; 

    Node(int val){
        data = val; 
        left = right = nullptr; 
    }
};

void inordered(Node* root){
    if(root == nullptr) return; 
    inordered(root->left);
    cout << root->data << " ";
    inordered(root->right);
}

void preordered(Node* root){
    if(root == nullptr) return; 
    cout << root->data << " ";
    preordered(root->left);
    preordered(root->right);
}

void postordered(Node* root){
    if(root == nullptr) return; 
    postordered(root->left);
    postordered(root->right);
    cout << root->data << " ";
}

int countNodes(Node* root){
    if(root == nullptr) return 0; 
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumOfNodes(Node* root){
    if(root == nullptr) return 0; 
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

bool searchNode(Node* root, int x){
    if(root == nullptr) return false;
    if(root->data == x) return true; 
    return searchNode(root->left, x) || searchNode(root->right, x);
};

int height(Node* root){
    if(root == nullptr) return -1; 
    return 1 + max(height(root->right), height(root->left));
}

int main(){
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout << "Inordered: ";
    inordered(root);
    cout << endl; 
    
    cout << "Preordered: ";
    preordered(root);
    cout << endl;

    cout << "Postordered: ";
    postordered(root);
    cout << endl; 
    
    cout << "Count of Nodes: " << countNodes(root) << endl;

    cout << "Height of Tres: " << height(root) << endl; 
    return 0; 
}