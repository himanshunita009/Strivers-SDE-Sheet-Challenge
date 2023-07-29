int solve(BinaryTreeNode<int>* root,int h){
    if(root){
        int l = solve(root->left,h);
        int r = solve(root->right,h);
        if(l == -1 || r == -1)
            return -1;
        int temp = abs(l-r);
        if(temp > 1)
            return -1;
        return max(l,r)+1;
    }
    return h;
}
bool isBalancedBT(TreeNode* root) {
    return solve(root,0)!=-1;
}