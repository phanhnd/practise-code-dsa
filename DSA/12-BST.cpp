//BST
#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data; 
    Node* left; 
    Node* right; 
    
    Node(int V){
        data = V; 
        left = right = nullptr; 
    }
};

Node* insert(Node* root, int value){
    if(root == nullptr) return new Node(value);

    if(value < root->data) 
        root->left = insert(root->left, value);
    else 
        root->right = insert(root->right, value);
    
    return root; 
}

void inordered(Node* root){
    if(root == nullptr) return; 

    inordered(root->left);
    cout << root->data << " ";
    inordered(root->right);
}

bool searchValue(Node* root, int value){
    if(root == nullptr) return false; 
    if(root->data == value) return true; 
    if(root->data < value) return searchValue(root->left, value);
    else return searchValue(root->right, value);
}

Node* findMin(Node* root){
    while(root && root->left != nullptr)
        root = root->left;
    return root; 
}

Node* findMax(Node* root){
    while(root && root->right != nullptr)
        root = root->right; 
    return root;
}

int height(Node* root){
    if(root == nullptr) return 0; 
    return max(height(root->left), height(root->right)) + 1; 
}

Node* deleteNode(Node* root, int key){
    if(!root) return root; 

    if(key < root->data) 
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else{
        if(!root->left) {
            Node* temp = root->right; 
            delete root; 
            return temp;
        }
        else if(!root->right) {
            Node* temp = root->left; 
            delete root; 
            return temp; 
        }
        Node* temp = findMin(root->right);
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data);
    }
    return root; 
}

int main(){
    Node* root = nullptr; 
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inordered Traversal: ";
    inordered(root);
    cout << endl; 
    Node* minNode = findMin(root);
    int minResult = minNode->data;
    cout << "Min of root: " << minResult << endl; 

    Node* maxNode = findMax(root);
    int maxResult = maxNode->data;
    cout << "Max of root: " << maxResult << endl; 

    cout << "Height of tree: " << height(root) << endl; 
    return 0; 
}