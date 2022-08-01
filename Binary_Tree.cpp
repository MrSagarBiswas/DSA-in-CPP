#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class BinaryTree {
    public:
    int val;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree (int k){
        val = k;
        left = right = NULL;
    }
};

void printTree(BinaryTree* tree) {
    if(tree == NULL)
        return;
    cout<<tree->val<<" ";
    printTree(tree->left);
    printTree(tree->right);
}

void kthNode(BinaryTree* tree, int k){
    if(tree == NULL)
        return;
    if(k == 0){
        cout<<tree->val<<" ";
        return;
    }
    kthNode(tree->left, k-1);
    kthNode(tree->right, k-1);
}

int treeHeight(BinaryTree* tree){
    if(tree == NULL)
        return 0;
    return max(treeHeight(tree->left), treeHeight(tree->right)) + 1;
}

void levelTraversal2(BinaryTree* tree){
    int height = treeHeight(tree);
    for(int i=0; i<height; i++){
        kthNode(tree, i);
        cout<<endl;
    }
}

void levelTraversal(BinaryTree* tree){
    queue<BinaryTree*> q;
    if(tree==NULL) return;
    q.push(tree);
    while(!q.empty()){
        BinaryTree* node = q.front();
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

int maxTree2(BinaryTree* tree){
    queue<BinaryTree*> q;
    int M = INT_MIN;
    if(tree!=NULL){
        q.push(tree);
        while(!q.empty()){
            BinaryTree* node = q.front();
            M = max(M, node->val);
            q.pop();
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }
    }
    return M;
}

int maxTree(BinaryTree* tree){
    if(tree == NULL)
        return INT_MIN;
    return max(tree->val, max(maxTree(tree->left), maxTree(tree->right)));
}

int sizeTree(BinaryTree* tree){
    if(tree == NULL)
        return 0;
    return 1 + sizeTree(tree->left) + sizeTree(tree->right);
}

string kthNodes(BinaryTree* root, int k, string s = ""){
    if(root==NULL){
        return s += "N";
    }
    if(k==0){
        return s += to_string(root->val);
    }
    return kthNodes(root->left, k-1, s) + kthNodes(root->right, k-1, s);
}

void iterativeInorder(BinaryTree* root){
    stack<BinaryTree*> s;
    BinaryTree* curr = root;
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->val<<" ";
        curr = curr->right;
    }
}

void iterativePreorder(BinaryTree* root) {
    stack<BinaryTree*> st;
    st.push(root);
    while(!st.empty()){
        BinaryTree* curr = st.top();
        cout<<curr->val<< " ";
        st.pop();
        if(curr->right != NULL) st.push(curr->right);
        if(curr->left != NULL) st.push(curr->left);
    }
}


int main()
{
    BinaryTree* tree = new BinaryTree(10);
    tree->left = new BinaryTree(20);
    tree->right = new BinaryTree(30);
    tree->left->right = new BinaryTree(40);

    printTree(tree);
    cout<<endl;
    kthNode(tree, 1);
    cout<<endl;
    cout<<kthNodes(tree, 1);
    cout<<endl;
    levelTraversal(tree);
    cout<<endl;
    levelTraversal2(tree);
    cout<<endl;
    iterativeInorder(tree);
    cout<<endl;
    iterativePreorder(tree);
    cout<<endl;
    cout<<endl;
    cout<<sizeTree(tree)<<endl;
    cout<<maxTree(tree);
    return 0;
}