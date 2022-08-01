#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int val;
    Node* left = NULL;
    Node* right = NULL;
    Node(int n){
        val = n;
    }
};

Node* insertRecursively(Node* root, int n){
    if(root == NULL)
        return new Node(n);
    else if(root->val > n)
        root->left = insertRecursively(root->left, n);
    else if(root->val < n)
        root->right = insertRecursively(root->right, n);
    return root;
}

void insert(Node* root, int n){
    Node* newNode = new Node(n);
    if(root == NULL){
        root = newNode;
    }
    while(root != NULL){
        if(root->val == n)
            return;
        else if(root->val > n){
            if(root->left != NULL){
                root = root->left;
            } else {
                root->left = newNode;
                return;
            }
        }
        else {
            if(root->right != NULL){
                root = root->right;
            } else {
                root->right = newNode;
                return;
            }
        }
    }
}

bool search(Node* root, int n){
    if(root == NULL)
        return false;
    if(root->val == n)
        return true;
    if(root->val > n)
        return search(root->left, n);
    else return search(root->right, n);
}

bool search1(Node* root, int n){
    while(root != NULL){
        if(root->val == n)
            return true;
        else if(root->val > n){
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return false;
}


void levelTraversal(Node* tree){
    queue<Node*> q;
    if(tree==NULL) return;
    q.push(tree);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        cout<<node->val<<" ";
        if( node->left != NULL){
            q.push(node->left);
        }
        if( node->right != NULL){
            q.push(node->right);
        }
    }
}

void deleteBST(Node* root, int val){
    if(root == NULL)
        return;
    if(root->left != NULL && root->left->val == val){
        root->left = root->left->;
    }
    if(root->right != NULL && root->right->val == val){
        delete(root->right);
        root->right = NULL;
    }
    if(root->val > val)
        deleteBST(root->left, val);
    else if(root->val < val)
        deleteBST(root->right, val);
    else {
        delete(root);
        root = NULL;
    }
}

int main()
{
    Node* root = new Node(20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 60);
    insert(root, 40);
    insert(root, 90);
    insertRecursively(root, 50);
    insert(root, 5);
    deleteBST(root, 50);
    levelTraversal(root);
    cout<<endl;
    cout<<search1(root, 5);
    return 0;
}