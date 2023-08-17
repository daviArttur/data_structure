#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    
    Node(int n) {
        val = n;        
    }
};

void preOrder(Node *n) {
    cout << n->val << endl;

    if (n->left != nullptr) {
        preOrder(n->left);
    }
    
    if (n->right != nullptr) {
        preOrder(n->right);
    }
}

void inOrder(Node *n) {
    if (n->left != nullptr) {
        inOrder(n->left);
    }
    cout << n->val << endl;
    if (n->right != nullptr) {
        inOrder(n->right);
    }
}

void postOrder(Node *n) {
        
    if (n->left != nullptr) {
        postOrder(n->left);
    }
    
    if (n->right != nullptr) {
        postOrder(n->right);
    }
    
    cout << n->val << endl;
}

int main()
{
    Node *n1 = new Node(4);
    n1->right = new Node(3);
    n1->left = new Node(2);
    
    Node *n4 = new Node(6);
    n4->left = new Node(7);
    n4->right = new Node(8);
    
    Node *root = new Node(5);
    root->right = n4; root->left = n1;
    
    preOrder(root);
    cout << endl << "------------------------" << endl;    
    inOrder(root);
    cout << endl << "------------------------" << endl;
    postOrder(root);
  
    return 0;
}
