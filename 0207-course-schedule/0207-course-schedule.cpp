class Solution {
public:
    bool dfs(vector<int> list[],vector<int> &vis,vector<int> &path,int i)
    {
        vis[i]=1;
        path[i]=1;
        for(auto it:list[i])
        {
            
            if(vis[it]==0)
            {
                if(dfs(list,vis,path,it)==true)return true;
            }
            else if(path[it])
            {
                return true;
            }
            
        }
        path[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> list[n];
        vector<int> vis(n,0);
        vector<int> path(n,0);

        for(auto it: prerequisites)
        {
            list[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(list,vis,path,i)==true)return false;
            }
        }
        return true;
       
        
        
        
    }
};