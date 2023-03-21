class Solution {
public:
    string reverseWords(string s) 
    {
        int n = s.size();
        vector<string>vobj;
        for(int i=0;i<n;i++)
        {
            if(s[i] == ' ')
                continue;
            else
            {
                string str;
                while(i<n && s[i] != ' ')
                {
                    str = str + s[i];
                    i++;
                }
                vobj.push_back(str);
            }
            
        }
        string ans;
        reverse(vobj.begin(),vobj.end());
        for(auto &it : vobj)
        {
            ans = ans + it;
            ans = ans + ' ';
        }
        ans.pop_back();
        return ans;
    }
};
