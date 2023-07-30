int solve(TreeNode * root,int & ans){
    if(root){
        int left = solve(root->left,ans);
        int right = solve(root->right,ans);
        ans = max(ans,left+right+1);
        return max(left+1,right+1);
    }
    return 0;
}
int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    solve(root,ans);
    return ans-1;
}