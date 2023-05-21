class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isPossible(int node,bool graph[101][101],int col,int m,int n,int color[])
    {
        for(int k=0;k<n;k++)
        {
            if(k != node && graph[k][node]==1 && color[k] == col)
                return false;
                
        }
        return true;
    }
    bool fun(int node,bool graph[101][101],int m,int n,int color[])
    {
        if(node == n)
            return true;
        for(int col=1;col<=m;col++)
        {
            
            if(isPossible(node,graph,col,m,n,color)){
                color[node] = col;
                if(fun(node+1,graph,m,n,color))
                    return true;
                else
                    color[node] = 0;
            }
            
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) 
    {
        int color[n] = {0};
        return fun(0,graph,m,n,color);
    }
};
