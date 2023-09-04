class Solution {
public:
    vector<vector<char>> ans;
//     vector<int> getNum(vector<vector<char>>& board, int r, int c) {
//     vector<int> choice;
//     int row[9] = {0};

//     for (int i = 0; i < 9; i++) {
//         int n = board[i][c] - '0';
//         if (n > 0) row[n - 1]++;
//     }

//     for (int i = 0; i < 9; i++) {
//         int n = board[r][i] - '0';
//         if (n > 0) row[n - 1]++;
//     }

//     int startRow = (r / 3) * 3;
//     int startCol = (c / 3) * 3;
//     for (int i = startRow; i < startRow + 3; i++) {
//         for (int j = startCol; j < startCol + 3; j++) {
//             int n = board[i][j] - '0';
//             if (n > 0) row[n - 1]++;
//         }
//     }

//     for (int i = 0; i < 9; i++) {
//         if (row[i] == 0) {
//             choice.push_back(i + 1);
//         }
//     }

//     return choice;
//     }

    vector<int> getNum(vector<vector<char>> &board,int r,int c)
    {
        vector<int> choice;
        vector<int> row(9,0);
        for(int i=0;i<9;i++)
        {
            int n=board[i][c]-'0';
            if(n>0)row[n-1]++;
        } 
        for(int i=0;i<9;i++)
        {
            int n=board[r][i]-'0';
           
            if(n>0)row[n-1]++;
        }
            int startRow = (r / 3) * 3;
    int startCol = (c / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            int n = board[i][j] - '0';
            if (n > 0) row[n - 1]++;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (row[i] == 0) {
            choice.push_back(i + 1);
        }
    }
        // if((r>=0 && r<=2 )&&(c>=0 && c<=2))
        // {
        //     for(int i=0;i<=2;i++)
        //     {
        //         for(int j=0;j<=2;j++)
        //         {
        //             int n=board[i][j]-'0';
        //             if(n>0)row[n-1]++;
        //         }
        //     }
        // }
        // else if((r>=0 && r<=2 )&&(c>=3 && c<=5))
        // {
        //     for(int i=0;i<=2;i++)
        //     {
        //         for(int j=3;j<=5;j++)
        //         {
        //             int n=board[i][j]-'0';
        //             if(n>0)row[n-1]++;
        //         }
        //     }
        // }
        // else if((r>=0 && r<=2 )&&(c>=6 && c<=8))
        // {
        //     for(int i=0;i<=2;i++)
        //     {
        //         for(int j=6;j<=8;j++)
        //         {
        //             int n=board[i][j]-'0';
        //             if(n>0)row[n-1]++;
        //         }
        //     }
        // }
        // else if((r>=2 && r<=5 )&&(c>=0 && c<=2))
        // {
        //     for(int i=2;i<=5;i++)
        //     {
        //         for(int j=0;j<=2;j++)
        //         {
        //             int n=board[i][j]-'0';
        //             if(n>0)row[n-1]++;
        //         }
        //     }
        // }
        // else if((r>=2 && r<=5 )&&(c>=3 && c<=5))
        // {
        //     for(int i=2;i<=5;i++)
        //     {
        //         for(int j=3;j<=5;j++)
        //         {
        //             int n=board[i][j]-'0';
        //             if(n>0)row[n-1]++;
        //         }
        //     }
        // }
        // else if((r>=2 && r<=5 )&&(c>=6 && c<=8))
        // {
        //     for(int i=2;i<=5;i++)
        //     {
        //         for(int j=6;j<=8;j++)
        //         {
        //             int n=board[i][j]-'0';
        //             if(n>0)row[n-1]++;
        //         }
        //     }
        // }
        // else if((r>=6 && r<=8 )&&(c>=0 && c<=2))
        // {
        //     for(int i=6;i<=8;i++)
        //     {
        //         for(int j=0;j<=2;j++)
        //         {
        //             int n=board[i][j]-'0';
        //             if(n>0)row[n-1]++;
        //         }
        //     }
        // }
        // else if((r>=6 && r<=8 )&&(c>=3 && c<=5))
        // {
        //     for(int i=6;i<=8;i++)
        //     {
        //         for(int j=3;j<=5;j++)
        //         {
        //             int n=board[i][j]-'0';
        //             if(n>0)row[n-1]++;
        //         }
        //     }
        // }
        // else if((r>=6 && r<=8 )&&(c>=6 && c<=8))
        // {
        //     for(int i=6;i<=8;i++)
        //     {
        //         for(int j=6;j<=8;j++)
        //         {
        //             int n=board[i][j]-'0';
        //             if(n>0)row[n-1]++;
        //         }
        //     }
        // }
        // for(int i=0;i<row.size();i++)
        // {
        //     if(row[i]==0)
        //     {
        //         choice.push_back(i+1);
        //     }
        // }
        // return choice;
        return choice;
        
        
    }
    void solve(vector<vector<char>>& board,int r,int c)
    {
        if(c==board.size())
        {
            solve(board,r+1,0);
            return;
            
        }
            
        if(r==9)
        {
            ans=board;
            return;
        }
        
            if(board[r][c]=='.')
            {
                    vector<int> choice =getNum(board,r,c);
                    if(choice.size()==0)return;
                    
                    for(int k=0;k<choice.size();k++)
                    {
                        int n=choice[k];
                        board[r][c] = (char)(n + '0');
                        solve(board,r,c+1);
                    }
                    board[r][c]='.';
                    return;  
            }
            else
            {
                solve(board,r,c+1);
            }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        //  vector<int> choice =getNum(board,7,3);
        // for(int i=0;i<choice.size();i++)
        //     cout<<choice[i]<<" ";
        board=ans;
        return ;
    }
};