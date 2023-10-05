#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node *left;
	Node *right;
};
Node* create(int item) {  
    Node* node = new Node;  
    node->data = item;  
    node->left = node->right = NULL;  
    return node;  
}  
Node* insertion(Node* root, int item) {  
    if (root == NULL)  
        return create(item); /*return new node if tree is empty*/  
    if (item < root->data)  
        root->left = insertion(root->left, item);  
    else  
        root->right = insertion(root->right, item);  
    return root;  
}  

Node* search(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL)
        return root;
        if(root->data == key){
            cout << "element found" ;
        }
       
    if (root->data < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}
void inorder(Node *root){  
    if (root == NULL)  
        return;  
    inorder(root->left); //traverse left subtree  
    cout<< root->data << "   "; //traverse root node  
    inorder(root->right); //traverse right subtree  
}  

/*Node* deletion(Node* root, int key)
{
    if (root == NULL)
        return NULL;
 
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key)
            return NULL;
        else
            return root;
    }
    return root;
}*/
int main() {
Node* root = NULL;  
  root = insertion(root, 45);  
  root = insertion(root, 30);  
  root = insertion(root, 50);  
  root = insertion(root, 25);  
  inorder(root);  
  search(root,45);
//  deletion(root,45);
  inorder(root);
  return 0;
}