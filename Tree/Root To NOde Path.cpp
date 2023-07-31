void solve(BinaryTreeNode<int>* root,string str,vector<string> & ans){
    if(root){
        if(!str.empty())
            str.push_back(' ');
        str += to_string(root->data);
        if(!root->left && !root->right)
            ans.push_back(str);
        if(root->left)
            solve(root->left,str,ans);
        if(root->right)
            solve(root->right,str,ans);
    }
}
vector<string> allRootToLeaf(BinaryTreeNode<int>* root) {
    vector<string> ans;
    solve(root,"",ans);
    return ans;
}