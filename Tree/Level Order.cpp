vector<vector<int>> levelOrder(TreeNode* root) {
    queue<pair<int,TreeNode*>> que;
    que.push({1,root});
    vector<vector<int>> ans;
    while (!que.empty()){
        int level = que.front().first;
        TreeNode * node = que.front().second;
        que.pop();
        if(ans.size() < level)
            ans.push_back({node->data});
        else
            ans[level-1].push_back(node->data);
        if(node->right)
            que.push({level+1,node->right});
        if(node->left)
            que.push({level+1,node->left});
    }
    return ans;
}