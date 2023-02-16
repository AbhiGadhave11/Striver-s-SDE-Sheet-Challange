class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
         if(s[0]==')'||s[0]=='}' || s[0] == ']')
            {
                return false;
            }
        for(int i=0;i<s.size();i++ )
        {
            if(s[i]=='('||s[i]=='{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            if(s[i] == ')')
            {
                if(st.size() != 0)
                {
                    if(st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                        return false;
                }
                else
                    return false;
                
            }
            
            else if(s[i] == '}')
            {
                if(st.size() != 0)
                {
                    if(st.top() == '{')
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
                    

            }
            
            else if(s[i] == ']')
            {
                if(st.size() != 0)
                {
                    if(st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
                
            }
        }
        if(st.size() == 0)
            return true;
        return false;
    }
};
