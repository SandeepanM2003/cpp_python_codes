#include<iostream>
using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int key;
    int height;

};

int height(Node* N){ // to get the height of a node
    if(N == NULL){
        return 0;
    }
    else{
        return N->height;
    }
}

int max(int a, int b){ // a utility function to get the maximum of two integers
    return (a>b)?a:b;
}

Node* newNode(int key){ // to create a new node
    Node* node = new Node();
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->height = 1;
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    // perform rotation
    x->right = y;
    y->left = T2;

    //update heights
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;

    // return new root
    return x;

}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    //perform rotation
    y->left = x;
    x->right = T2;

    //upadate heights
     y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;

    //return new root
    return y;
}

int getBalance(Node* N){
    if(N == NULL){
        return 0;
    }
    return height(N->left)-height(N->right);
}

Node* insert(Node* node,int key){
    if(node == NULL){
        return newNode(key);
    }

    if(key < node->key){
        node->left = insert(node->left,key);
    }
    else if(key > node->key){
        node->right = insert(node->right,key);
    }
    else{
        return node;
    }

    // update height
    node->height = max(height(node->left),height(node->right)) + 1;

    int balance = getBalance(node);

    // rotations

    if(balance > 1 && key < node->left->key){
        return rightRotate(node);
    }

    if(balance > 1 && key > node->left->key){
        node->left  = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && key > node->right->key){
        return leftRotate(node);
    }

    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;

    }

    void preorderTraversal(Node* root){
        if(root == NULL){
            return;
        }
        cout<< root->key<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);

    }


int main(){

    Node* root = NULL;

    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,50);
    root = insert(root,25);
    

    preorderTraversal(root); 



    return 0;
}