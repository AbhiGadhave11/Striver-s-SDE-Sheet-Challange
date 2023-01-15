int calculateMinPatforms(int at[], int dt[], int n) 
{
    sort(at,at+n);
    sort(dt,dt+n);
    int i = 1,j = 0;
    int platform_needed = 1,ans = 1;
    while(i<n&&j<n)
    {
        if(at[i]<=dt[j])
        {
            platform_needed++;
            i++;
        }
        else if(at[i] > dt[j])
        {
            platform_needed--;
            j++;
        }
        ans = max(ans,platform_needed);
    }
    return ans;
    
}
