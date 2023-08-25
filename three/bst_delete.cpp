#include <iostream>

using namespace std;

struct Node {
    int data;
    int lvl;
    Node *left;
    Node *right;
    
    
    Node(int n, int l) {
        data = n;
        lvl = l;
    }
};

void inOrder(Node *n) {
    
    if(n->left) {
        inOrder(n->left);
    }
    
    cout << "key: " << n->data << " lvl: " << n->lvl << endl;
    
    if (n->right) {
        inOrder(n->right);
    }
}

Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}


Node* Delete(Node *root, int data) {
    
if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);

	else {
		
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
	
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
	
		else { 
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
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
    
   Delete(root, 7);
    inOrder(root);
    return 0;
}
