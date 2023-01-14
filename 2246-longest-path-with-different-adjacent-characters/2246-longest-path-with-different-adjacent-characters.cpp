class Solution {
public:
   
    int maxi2=0;
    int solve(string &s,vector<vector<int>> &adj,int k)
    {
        int maxi=0;
        int ans=0;
         for(int i=0;i<adj[k].size();i++)
         {
             
             ans=1+solve(s,adj,adj[k][i]);
             if(s[k]!=s[adj[k][i]])
             {
                 if(maxi2< maxi+ans)maxi2=maxi+ans;
                 maxi=max(maxi,ans);
                
             }
             ans=0;     
         }
        return maxi;
    }
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> adj(parent.size());
        for(int i=1;i<parent.size();i++)
        {
            adj[parent[i]].push_back(i);
        }
        solve(s,adj,0);
        return maxi2+1;
    }
};