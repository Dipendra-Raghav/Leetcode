class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int i,vector<int> &vis,vector<int> &ans)
    {
        
        if(graph[i].size()==0)return true;
        if(vis[i]==2)return true;
       //if(vis[i]==1)return false;
        vis[i]=1;
        bool chk=true;
        for(auto it: graph[i])
        {
            
            if(vis[it]==-1)
            {
                chk=chk&&dfs(graph,it,vis,ans);
            }
            else if(vis[it]==2)
            {
                chk=chk&&true;
            }
            else
                return false;
        }
        if(chk)
        {
            vis[i]=2;
            ans.push_back(i);
        }
        return chk;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            dfs(graph,i,vis,ans);
            if(graph[i].size()==0)
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};