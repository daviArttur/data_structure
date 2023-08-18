#include <iostream>

using namespace std;

struct Node {
    int key;
    int lvl;
    Node *left;
    Node *right;
    
    
    Node(int n, int l) {
        key = n;
        lvl = l;
    }
};

void inOrder(Node *n) {
    
    if(n->left) {
        inOrder(n->left);
    }
    
    cout << "key: " << n->key << " lvl: " << n->lvl << endl;
    
    if (n->right) {
        inOrder(n->right);
    }
}


Node* deleteNode(Node *root, int key) {
    
    if(root == nullptr) {
        return root;
    }
    else if(key > root->key) {
        root = deleteNode(root->right, key);
    } 
    else if(key < root->key) {
        root = deleteNode(root->left, key);
    } else {
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            root = NULL;
        } else if(root->left == nullptr) {
            cout << "AQUI " << root->key << endl;
            root = root->right;
        } else if(root->right == nullptr) {
            root = root->left;
        }
        return root;
    }
    
    return root;
}

int main()
{
    Node *root = new Node(5, 1);
    root->right = new Node(7, 2);
    // root->right->left = new Node(6, 3);
    root->right->right = new Node(14, 3);
    root->left = new Node(3, 2);
    root->left->right = new Node(4, 3);
    root->left->left = new Node(2, 3);
    
    deleteNode(root, 7);
    inOrder(root);
    return 0;
}
