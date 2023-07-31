vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(!root)
        return ans;
    map<int,int> mp;
    queue<pair<int,TreeNode*>> que;
    que.push({0,root});
    while (!que.empty()){
        int level = que.front().first;
        auto * node = que.front().second;
        que.pop();
        mp[level] = node->val;
        if(node->left)
            que.push({level+1,node->left});
        if(node->right)
            que.push({level+1,node->right});
    }
    for(auto it : mp)
        ans.push_back(it.second);
    return ans;
}