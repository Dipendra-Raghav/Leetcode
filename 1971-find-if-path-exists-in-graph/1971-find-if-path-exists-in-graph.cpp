class Solution {
public:
    
    bool solve(vector<int> adj[],int k, int dest,vector<int> &path)
    {
        if(k==dest)
        {
            return true;
        }
        path[k]=1;
        
        for(int i=0;i<adj[k].size();i++)
        {
           if(path[adj[k][i]]==0)
            {
                if(solve(adj,adj[k][i],dest,path))
                return true;
            }
           
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       
        if(source==destination)return true;
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> path(n,0);
        if(solve(adj,source,destination,path))return true;
        return false;;
        
    }
};