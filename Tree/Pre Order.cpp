template <typename T>
class BinaryTreeNode {
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

void preOrder(BinaryTreeNode<int> *root) {
    if(root){
        cout<<root->data<<"\t";
        preOrder(root->left);
        preOrder(root->right);
    }
}

//Using Stack
void preOrder(BinaryTreeNode<int> *root) {
    stack<BinaryTreeNode<int>*> st;
    st.push(root);
    while(!st.empty()){
        auto next = st.top();
        st.pop();
        cout<<next->data<<"\t";
        if(next->right)
            st.push(next->right);
        if(next->left)
            st.push(next->left);
    }
}