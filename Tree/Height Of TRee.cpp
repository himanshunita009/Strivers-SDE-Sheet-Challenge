//Using Stack
int solve(TreeNode * root,int h){
    if(root){
        int l = solve(root->left,h);
        int r = solve(root->right,h);
        return max(l,r)+1;
    }
    return h;
}
int maxDepth(TreeNode* root) {
    return solve(root,0);
}

//Using Queue
int maxDepth(TreeNode* root) {
    int ans = 0;
    if(!root)
        return ans;
    queue<pair<int,TreeNode*>> que;
    que.push({1,root});
    while(!que.empty()){
        auto node = que.front();
        que.pop();
        ans = max(ans,node.first);
        if(node.second->left)
            que.push({node.first+1,node.second->left});
        if(node.second->right)
            que.push({node.first+1,node.second->right});
    }
    return ans;
}