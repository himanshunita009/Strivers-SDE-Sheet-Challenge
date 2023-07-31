int solve(TreeNode* root,int a,int b,int & ans){
    if(root && ans == -1){
        int l = solve(root->left,a,b,ans);
        int r = solve(root->right,a,b,ans);
        if(l != -1 || r != -1){
            if((l == a && r == b) || (l == b && r == a))
                ans = root->data;
            else if((root->data == a && (l == b || r == b)) || (root->data == b && (l == a || r == a)))
                ans = root->data;
            return (l!=-1)?l:r;
        }
        else if(root->data == a || root->data == b){
            return root->data;
        }else
            return -1;
    }
    return -1;
}
int lca(TreeNode* root,int a,int b){
    int ans = -1;
    solve(root,a,b,ans);
    return ans;
}