class Solution {
public:
int solve(string s,vector<vector<int>> adj,int k)
{
int ans=0;
for(int i=0;i<adj[k].size();i++)
{
if(s[adj[k][i]]!=s[k])
{
ans= 1+solve(s,adj,adj[k][i]);
}
}
return ans;
}
int longestPath(vector<int>& parent, string s) {
vector<vector<int>> adj(parent.size());
for(int i=1;i<parent.size();i++)
{
adj[parent[i]].push_back(i);
}
return 1+ solve(s,adj,0);
}
};