void printLeftView(BinaryTreeNode<int> *root){
    if(!root)
        return;
    map<int,int> mp;
    queue<pair<int,BinaryTreeNode<int>*>> que;
    que.push({0,root});
    while (!que.empty()){
        int level = que.front().first;
        auto * node = que.front().second;
        que.pop();
        if(mp.find(level) == mp.end())
            mp[level] = node->data;
        if(node->left)
            que.push({level+1,node->left});
        if(node->right)
            que.push({level+1,node->right});
    }
    for(auto it : mp)
        cout<<it.second<<"\t";
}