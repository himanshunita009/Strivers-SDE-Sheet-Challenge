Node* createTree(vector<int>&arr){
    Node * root = new Node(arr[0]);
    Node * left = new Node(arr[1]);
    Node * right = new Node(arr[2]);
    root->left = left;
    root->right = right;
    left->left = new Node(arr[3]);
    left->right = new Node(arr[4]);
    right->left = new Node(arr[5]);
    right->right = new Node(arr[6]);
    return root;
}