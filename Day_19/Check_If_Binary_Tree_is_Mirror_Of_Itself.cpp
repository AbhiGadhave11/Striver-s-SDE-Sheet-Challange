class Solution {
    private:
    void fun(Node *root)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
            return;
        fun(root->left);
        fun(root->right);
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        fun(node);
    }
};
