bool solve(BinaryTreeNode<int>* root1,BinaryTreeNode<int> * root2){
    if(!root1 && !root2)
        return true;
    if(!root1 && root2)
        return false;
    if(root1 && !root2)
        return false;
    if(root1->data != root2->data)
        return false;
    if(!solve(root1->left,root2->right))
        return false;
    return solve(root1->right,root2->left);
}
bool isSymmetric(BinaryTreeNode<int>* root) {
    if(!root)
        return true;
    return solve(root->left,root->right);
}