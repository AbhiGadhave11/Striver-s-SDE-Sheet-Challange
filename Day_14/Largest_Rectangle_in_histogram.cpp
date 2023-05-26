class Solution {
public:
    int largestRectangleArea(vector<int>& histo) 
    {
        int n = histo.size();
        int maxi = 0;
        
        stack<int>st;
        for(int i=0;i<=n;i++)
        {
            while(st.size()!= 0 && (i==n || histo[st.top()]>= histo[i]))
            {
                int height = histo[st.top()];
                int width = 0;
                st.pop();
                if(st.size()==0)
                    width = i;
                else
                    width = i-st.top()-1;
                
                maxi = max(maxi,width*height); 
            }
            st.push(i);
         }
        return maxi;
        
    }
};
