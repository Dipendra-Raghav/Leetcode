class Solution {
public:
    void solve(int i,vector<vector<int>>& isConnected, vector<int> &adj)
    {
        adj[i]=-1;
        for(int j=0;j<isConnected[i].size();j++)
        {
            if(isConnected[i][j]==1 && adj[j]!=-1)
            {
                solve(j,isConnected,adj);
            }
            
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj(n+1,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(adj[i]!=-1)
            {
                solve(i,isConnected,adj);
                ans++;
            }
            
        }
        return ans;
        
    }
};