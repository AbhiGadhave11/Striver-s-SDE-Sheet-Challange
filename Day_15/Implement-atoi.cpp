class Solution {
public:
    int myAtoi(string s) 
    {
        int start = 0;
        int n = s.size();
        while(start<n && s[start] == ' '  )
            start++;
        if(start == n)
            return 0;
        long long ans = 0;
        int isneg = 1;
        if(s[start] == '-'){
            isneg = -1;
            start++;
        }
        else if(s[start] == '+')
            start++;
        
        while(start<n && isdigit(s[start]))
        {
            ans = (ans*10)+(s[start]-'0');
            if(ans*isneg >= INT_MAX)
                return INT_MAX;
            if((ans*isneg) <= INT_MIN)
                return INT_MIN;
            start++;
        }
        return (int)ans*isneg;
        
    }
};
