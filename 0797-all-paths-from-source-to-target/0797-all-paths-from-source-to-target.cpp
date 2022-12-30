class Solution {
public:
    void solve(vector<vector<int>>& graph,int k,vector<vector<int>> &ans,vector<int> res,vector<int> visited)
    {
        if(visited[k]!=-1)return;
        res.push_back(k);
        if(k==graph.size()-1)
        {
            ans.push_back(res);
        }
        for(int i=0;i<graph[k].size();i++)
        {
            solve(graph,graph[k][i],ans,res,visited);
        }
        visited[k]=-1;
        res.pop_back();
        return; 
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> res;
        vector<int> visited(graph.size(),-1);
        solve(graph,0,ans,res,visited);
        return ans;
               
    }
};