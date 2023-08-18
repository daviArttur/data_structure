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

void insert(Node *&root, Node *newNode, int lvl = 1) {
    if (root == nullptr) {
        newNode->lvl = lvl;
        root = newNode;
        return;
    }
    
   if (newNode->key > root->key) {
        insert(root->right, newNode, lvl + 1);
    } else if (newNode->key < root->key) {
        insert(root->left, newNode, lvl + 1);
    }
}

int main()
{
    Node *root = new Node(5, 1);
    root->right = new Node(7, 2);
    root->right->left = new Node(6, 3);
    root->right->right = new Node(14, 3);
    root->left = new Node(3, 2);
    root->left->right = new Node(4, 3);
    root->left->left = new Node(2, 3);
    
    insert(root, new Node(12, 0));
    insert(root, new Node(9, 0));
    insert(root, new Node(8, 0));
    insert(root, new Node(13, 0));
    inOrder(root);
    return 0;
}
