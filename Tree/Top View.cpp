vector<int> topView(TreeNode *root){
    if(!root)
        return vector<int> {};
    map<int,int> mp;
    queue<pair<int,TreeNode*>> que;
    que.push({0,root});
    while (!que.empty()){
        int level = que.front().first;
        TreeNode * node = que.front().second;
        que.pop();
        if(mp.find(level) == mp.end())
            mp[level] = node->data;
        if(node->left)
            que.push({level-1,node->left});
        if(node->right)
            que.push({level+1,node->right});
    }
    vector<int> ans;
    for(auto it : mp)
        ans.push_back(it.second);
    return ans;
}