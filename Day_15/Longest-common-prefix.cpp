class Solution {
    private:
    string commonprefix(string &a,string &b)
    {
        int n = min(a.size(),b.size());
        int i = 0;
        for( i=0;i<n;i++)
        {
            if(a[i] != b[i])
                break;
        }
        return a.substr(0,i);
    }
    string divide(vector<string>& v,int left,int right)
    {
        if(left == right)
            return v[left];
        int mid = (left+right)/2;
        string leftlcf = divide(v,left,mid);
        string rightlcf = divide(v,mid+1,right);
        return commonprefix(leftlcf,rightlcf);
    }
public:
    string longestCommonPrefix(vector<string>& v) 
    {   
        return  divide(v,0,v.size()-1);
        
    }
};
