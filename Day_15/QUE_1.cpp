class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start=0,end=n-1;
        while(s[start]== ' ')
            start++;
        while(s[end] == ' ')
            end--;
        string ans = "";
        int ostart = start;
        string str = "";
        for(int i=ostart;i<=end;i++)
        {
            if(s[i] == ' ')
            {
                str = s.substr(start,i-start);
                str += ' ';
                str += ans;
                ans = str;
                while(s[i] == ' ')
                {
                    i++;
                }
                start = i;
                i--;
            }
        }
        str = s.substr(start,(end+1)-start);
        str += ' ';
        str += ans;
        ans = str;
        if(ans[ans.size()-1]==' ')
            ans.pop_back();
        return ans;
    }
};
