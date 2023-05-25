class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=0;i<n;i++)
            st.push(i);
        while(st.size() > 1)
        {
            int no1 = st.top();
            st.pop();
            int no2 = st.top();
            st.pop();
            if(M[no1][no2] == 1) 
            {
                //no1 knows no2 that's why no1 is not a celebrity  
                st.push(no2);
            }
            else
            {
                //no2 knows no1 that's why no2 is not a celebrity
                st.push(no1);
            }
        }
        int cele = st.top();
        st.pop();
        for(int i=0;i<n;i++)
        {
            if(M[cele][i] == 1 || M[i][cele] == 0)
            {
                return -1;
            }
        }
        return cele;
    }
};
