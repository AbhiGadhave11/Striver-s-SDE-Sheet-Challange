class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V,1e9);
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,S});
        dist[S] = 0;
        
        while(pq.size() != 0)
        {
            pair<int,int> p = pq.top();
            pq.pop();
            int node = p.second;
            int disWeight = p.first;
            for(auto &it : adj[node])
            {
                int dis = it[1];
                int nextnode = it[0];
                if(disWeight+dis < dist[nextnode])
                {
                    dist[nextnode] = disWeight+dis;
                    pq.push({dist[nextnode],nextnode});
                }
            }
        }
        return dist;
    }
};
