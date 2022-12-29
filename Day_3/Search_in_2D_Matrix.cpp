#include <bits/stdc++.h> 

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    
//     for(int i=0;i<m;i++){
//         vector<int>v;
//         for(int j=0;j<n;j++){
//             v.push_back(mat[i][j]);
//         }
//         if(binary_search(v.begin(), v.end(), target))
//             return true;
//     }
//     return false;
  
  // Second Approach :- 
    int low = 0,high = (m*n)-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        int i = mid/n;
        int j = mid%n;
        if(mat[i][j] == target)
            return true;
        else if(mat[i][j] < target)
        {
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return false;
    
    
}
