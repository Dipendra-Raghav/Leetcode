class Solution {
public:
    int n;
    int m;
    void solve(int i,int j,vector<vector<char>> &grid)
    {
        if(i<0 || j>=m || i>=n || j<0 || grid[i][j]=='0' || grid[i][j]=='-')return;
        
        grid[i][j]='-';
        solve(i-1,j,grid);
        solve(i,j-1,grid);
        solve(i+1,j,grid);
        solve(i,j+1,grid);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(grid.size()==0)
        return 0;
        int ans=0;
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    solve(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};