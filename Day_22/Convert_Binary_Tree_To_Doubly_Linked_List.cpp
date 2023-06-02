// This function should return head to the DLL
class Solution
{
    public: 
    Node *prev = NULL;
    void fun(Node *root)
    {
        if(root == NULL)
            return;
        fun(root->left);
        prev->right = root;
        root->left = prev;
        prev = root;
        fun(root->right);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        Node *dummy = new Node(-1);
        prev = dummy;
        fun(root);
        Node *head = dummy->right;
        dummy->right = head->left = NULL;
        return head;
    }
};
