class Solution
{
    private:
    int ans = 0;
    void inorder(Node *root,int &cnt,int k)
    {
        if(root == NULL)
            return;
        inorder(root->left,cnt,k);
        cnt++;
        if(cnt == k)
        {
            ans = root->data;
        }
        inorder(root->right,cnt,k);
    }
    void fun(Node *root,int &n)
    {
        if(root == NULL)
            return;
        fun(root->left,n);
        n++;
        fun(root->right,n);
    }
    public:
    int kthLargest(Node *root, int K)
    {
        int n = 0;
        fun(root,n);
        // cout<<n<<endl;
        int cnt = 0;
        inorder(root,cnt,n-K+1);
        
        return ans;
    }
};
