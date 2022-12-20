class Solution {
public:
    int ans=0;
    int n;
    void solve(vector<vector<int>>& rooms,int k,vector<int> &vis)
    {
        if(vis[k]==1)
        {
            return ;
        }
        vis[k]=1;
        ans++;
        for(int i=0;i<rooms[k].size();i++)
        {
            if(vis[rooms[k][i]]==0)
            {
                solve(rooms,rooms[k][i],vis);
            }
        }
        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n=rooms.size();
        vector<int> vis(n,0);
        solve(rooms,0,vis);
        bool anss=ans==n? true :false;
        return anss;
    }
};