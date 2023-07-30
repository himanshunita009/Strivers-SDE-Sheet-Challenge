int solve(TreeNode<int>* root,int & ans){
    if(root){
        int left = max(0,solve(root->left,ans));
        int right = max(0,solve(root->right,ans));
        ans = max(ans,left+right+root->data);
        return max(left,right)+root->data;
    }
    return 0;
}
int maxPathSum(TreeNode<int> *root){
    int ans = INT_MIN;
    solve(root,ans);
    return ans;

}