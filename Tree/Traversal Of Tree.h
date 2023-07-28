class BinaryTreeNode
{
public :
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

void inOrderTraversal(BinaryTreeNode * root,vector<int> & ans){
    if(root){
        inOrderTraversal(root->left,ans);
        ans.push_back(root->data);
        inOrderTraversal(root->right,ans);
    }
}

void preOrderTraversal(BinaryTreeNode * root,vector<int> & ans){
    if(root){
        ans.push_back(root->data);
        preOrderTraversal(root->left,ans);
        preOrderTraversal(root->right,ans);
    }
}

void postOrderTraversal(BinaryTreeNode * root,vector<int> & ans){
    if(root){
        postOrderTraversal(root->left,ans);
        postOrderTraversal(root->right,ans);
        ans.push_back(root->data);
    }
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode *root){
    vector<vector<int>> ans(3);
    inOrderTraversal(root,ans[0]);
    preOrderTraversal(root,ans[1]);
    postOrderTraversal(root,ans[2]);
    return ans;
}
