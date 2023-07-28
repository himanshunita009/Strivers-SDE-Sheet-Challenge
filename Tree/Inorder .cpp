void inOrderTraversal(BinaryTreeNode * root,vector<int> & ans){
    if(root){
        inOrderTraversal(root->left,ans);
        ans.push_back(root->data);
        inOrderTraversal(root->right,ans);
    }
}
//Using Stack
vector<int> getInOrderTraversal(TreeNode *root){
    stack<TreeNode*> st;
    TreeNode * current = root;
    vector<int> ans;
    while(!st.empty() || !current){
        if(current){
            st.push(current);
            current = current->left;
        }else {
            current = st.top();
            st.pop();
            ans.push_back(current->data);
            current = current->right;
        }
    }
    return ans;
}