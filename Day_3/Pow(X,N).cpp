#include <bits/stdc++.h> 

int modularExponentiation(int x, int n) 
{
    long long nn = n,ans = 1;
    while(n!=0)
    {
        if(n%2 != 0)
        {
            ans = ans *x;
            n = n-1;
        }
        else
        {
            x = x*x;
            n = n/2;
        }
    }
    
    return ans;

}
