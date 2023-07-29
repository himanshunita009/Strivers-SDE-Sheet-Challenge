vector<int> zigzagTreeTraversal(TreeNode<int> *root){
    queue<TreeNode<int>*> que;
    que.push(root);
    stack<TreeNode<int>*> st;
    vector<int> ans;
    int count = 1;
    while (!que.empty() || !st.empty()){
        while (!que.empty()){
            st.push(que.front());
            que.pop();
        }
        while (!st.empty()){
            auto node = st.top();
            st.pop();
            ans.push_back(node->data);
            if(count&1){
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }else {
                if(node->right)
                    que.push(node->right);
                if(node->left)
                    que.push(node->left);
            }
        }
        ++count;
    }
    return ans;
}
