class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<pair<int,int>,int>> q;
        maze[entrance[0]][entrance[1]] = '*';
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j== m-1) && maze[i][j]=='.'){
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                    
                }
                
            }
        }
        
        int row[]={-1,0,1,0};
        int col[]={0,-1,0,1};
        while(!q.empty())
        {
            
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr=r+row[i];
                int nc=c+col[i];
                if(min(nr, nc)<0 || nr>=maze.size() || nc>=maze[0].size() || vis[nr][nc]==1 || maze[nr][nc]=='+'){
                    continue;
                }
                if(maze[nr][nc]=='*'){
                    return d+1;
                }
                vis[nr][nc] = 1;
                q.push({{nr, nc}, d+1});
               
                
            }
        }
        return -1;
        
    }
};