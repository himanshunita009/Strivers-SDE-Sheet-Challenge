//
void postOrderTraversal(BinaryTreeNode * root,vector<int> & ans){
    if(root){
        postOrderTraversal(root->left,ans);
        postOrderTraversal(root->right,ans);
        ans.push_back(root->data);
    }
}

//Using STack
vector<int> postOrderTraversal(TreeNode * root){
    TreeNode * current = root;
    stack<TreeNode*> st;
    vector<int> ans;
    while (!st.empty() || current){
        if(current){
            st.push(current);
            current = current->left;
        }else {
            TreeNode* temp = st.top()->right;
            if(!temp){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }else {
                current = temp;
            }
        }
    }
    return ans;
}
//
// Created by himan on 7/28/2023.
//

