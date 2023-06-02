class Nodevalue{
    public:
    int maxvalue,minvalue,maxsize;
    Nodevalue(int maxi,int mini,int size)
    {
        this->maxvalue = maxi;
        this->minvalue = mini;
        this->maxsize = size;
    }
};

class Solution {
    private:
    Nodevalue LargestBST(Node *root)
    {
        if(root == NULL)
            return Nodevalue(INT_MIN,INT_MAX,0);
        auto left = LargestBST(root->left);
        auto right = LargestBST(root->right);
        if(left.maxvalue <root->data && root->data < right.minvalue)
        {
            return Nodevalue(max(root->data,right.maxvalue),min(root->data,left.minvalue),left.maxsize+right.maxsize+1);
        }
        return Nodevalue(INT_MAX,INT_MIN,max(left.maxsize,right.maxsize));
    }
public:
    int largestBst(Node* root) {
        auto aret = LargestBST(root);
        return aret.maxsize;
        
    }
};
