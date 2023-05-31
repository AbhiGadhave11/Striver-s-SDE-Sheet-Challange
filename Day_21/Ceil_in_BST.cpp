int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = 0;
    BinaryTreeNode<int> *curr = node;
    while(curr!= NULL)
    {
        if(curr->data < x)
        {
            curr = curr->right;
        }
        else {
            ans = curr->data;
            curr = curr->left;
        }
    }
    if(ans == 0 && x != 0)
        return -1;
    return ans;
}
