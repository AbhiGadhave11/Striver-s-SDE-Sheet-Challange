vector<int> Solution::dNums(vector<int> &arr, int B) 
{
    vector<int>ans;
    int n = arr.size();
    unordered_map<int,int>uobj;
    int i=0,j = 0;
    while(j<n)
    {
        uobj[arr[j]]++;
        if(j-i+1 < B)
            j++;
        else
        {
            ans.push_back(uobj.size());
            uobj[arr[i]]--;
            if(uobj[arr[i]] == 0)
                uobj.erase(arr[i]);
            i++;
            j++;
        }
    }
    return ans;
}
