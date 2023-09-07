class Solution {
public:
    bool solve(vector<int> nums[],vector<int> &vis,vector<int> &path,int j)
    {
        vis[j]=1;
        path[j]=1;
        for(int i=0;i<nums[j].size();i++)
        {
            if(path[nums[j][i]]==1)return false;
            else if(vis[nums[j][i]]==-1)
            {
                if(solve(nums,vis,path,nums[j][i])==false)return false;
            }
        }
        path[j]=-1;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> nums[n];
        for(int i=0;i<pre.size();i++)
        {
            nums[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int> vis(n,-1);
        vector<int> path(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                if(solve(nums,vis,path,i)==false)return false;
            }
            
        }
        return true;
        
    }
};