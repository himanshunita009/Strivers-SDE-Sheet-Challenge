bool isSameTree(TreeNode* root1, TreeNode* root2) {
    if(!root1 && !root2)
        return true;
    else if(!root1 && root2)
        return false;
    else if (root1 && !root2)
        return false;
    else if(root1->val != root2->val)
        return false;
    if(isSameTree(root1->left,root2->left))
        return isSameTree(root1->right,root2->right);
    return false;
}