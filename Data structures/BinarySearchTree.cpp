#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1010];
struct Node{

    int data;
    struct Node *left;
    struct Node *right;
};


Node* CreateNode(int x){
    // Create a new node with value x, it left and right is NULL for now
    Node* p = new Node();
    p->data=x;
    p->left = p->right = NULL;
    return p;
}

void addNode(Node* &root,int x){
    // we want root to be permanently alternate, therefore "&root"
    // x is int and root is Node*, so we must turn x into Node*
    Node* temp = CreateNode(x);
    //if this tree is empty
    if (root==NULL){
        root=temp;
    }
    // else we need to find where to insert this node
    else{
        if (root->data>=x)
            addNode(root->left, x);
        else
            addNode(root->right, x);
    }
}

int findheight(Node* root){
    if (root==NULL)
        return 0;

    int lh=0,rh=0;
    lh = findheight(root->left);
    rh = findheight(root->right);
    return max(lh,rh)+1;
}

int main(){
    // Initiate a root with NULL value
    Node* root = NULL;
    // read data from input
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    // Create a tree
    for (int i=1;i<=n;i++)
        addNode(root,a[i]);
    // Find the height of a tree
    cout<<findheight(root);
    return 0;
}




