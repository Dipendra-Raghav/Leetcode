class Solution {
public:
    int n,m;
    int ans=0;
    void solve(vector<vector<int>> &grid,int i,int j,int cnt)
    {
        if(i<0 || j<0 || i>=n ||j>=m || grid[i][j]==-1)return;
        if(grid[i][j]==2)
        {
            
            if(cnt==-1)
            {
                cout<<"hi";
                ans++;
                return ;
            }
            else
            {
                return;
            }
        }
        grid[i][j]=-1;
        
        solve(grid,i+1,j,cnt-1);
        
        solve(grid,i-1,j,cnt-1);
        
        solve(grid,i,j+1,cnt-1);
        
        solve(grid,i,j-1,cnt-1);
        grid[i][j]=0;
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)cnt++;
            }
        }
        cout<<cnt;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    
                    solve(grid,i,j,cnt);
                    return ans;
                }
                    
            }
        }
       
        return 0;
        
    }
};