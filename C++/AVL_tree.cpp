#include <iostream>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int key;
    int height;
};

// Function to get the height of a node
int height(Node* N) {
    if (N == NULL) {
        return 0;
    }
    else {
        return N->height;
    }
}

// Utility function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->height = 1;
    return node;
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return y;
}

// Get balance factor of a node
int getBalance(Node* N) {
    if (N == NULL) {
        return 0;
    }
    return height(N->left) - height(N->right);
}

// Function to insert a node into the AVL tree
Node* insert(Node* node, int key) {
    if (node == NULL) {
        return newNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    else {
        // Duplicate keys are not allowed
        return node;
    }

    // Update height
    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    // Perform rotations if needed
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to perform a preorder traversal of the AVL tree
void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->key << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
