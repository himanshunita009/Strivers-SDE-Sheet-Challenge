bool isLeaf(TreeNode<int> * node){
    return !node->left && !node->right;
}
void leftBoudaryTraversal(TreeNode<int>* root,vector<int> & ans){
    auto cur = root->left;
    while(cur){
        if(!isLeaf(cur))
            ans.push_back(cur->data);
        if(cur->left)
            cur = cur->left;
        else cur = cur->right;
    }
}
void rightBoundaryTraversal(TreeNode<int>* root,vector<int> & ans){
    auto cur = root->right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur))
            temp.push_back(cur->data);
        if(cur->right)
            cur = cur->right;
        else cur = cur->left;
    }
    for(int i = temp.size()-1;i>=0;--i)
        ans.push_back(temp[i]);
}
void inOrderTraversal(TreeNode<int>* root,vector<int> & ans){
    if(isLeaf(root))
        ans.push_back(root->data);
    if(root->left)
        inOrderTraversal(root->left,ans);
    if(root->right)
        inOrderTraversal(root->right,ans);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(!root)
        return ans;
    if(!isLeaf(root))
        ans.push_back(root->data);
    leftBoudaryTraversal(root,ans);
    inOrderTraversal(root,ans);
    rightBoundaryTraversal(root,ans);
    return ans;
}