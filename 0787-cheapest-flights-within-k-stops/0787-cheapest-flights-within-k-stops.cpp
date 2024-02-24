class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> path(n,INT_MAX);
        queue<pair<int,int>> q;
        q.push({src,0});
        path[src]=0;
        int steps=0;
        while(!q.empty() && steps<=k)
        {
            int N= q.size();
            while(N--)
            {
                int node= q.front().first;
                int dist = q.front().second;
                q.pop();
                for(int i=0;i<adj[node].size();i++)
                {
                    int nwNode = adj[node][i].first;
                    int nwDist = adj[node][i].second;
                    if(path[nwNode] > dist + nwDist)
                    {
                        path[nwNode]=dist + nwDist;
                        q.push({nwNode , dist+nwDist});
                    }
                }
            }
            steps++;
        }
        return path[dst] == INT_MAX ? -1 : path[dst];
    }
};