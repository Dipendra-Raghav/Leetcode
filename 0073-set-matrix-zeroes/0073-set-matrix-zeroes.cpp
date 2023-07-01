class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        
        int n=matrix[0].size();
        vector<int> row(n,INT_MIN);
        vector<int> col(m,INT_MIN); 
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[j]=0;
                    col[i]=0;
                }
            }
        }
       for(int i=0;i<n;i++)cout<<row[i]<<" ";
        cout<<endl;
        for(int i=0;i<m;i++)cout<<col[i]<<" ";
        

        for(int i=0;i<n;i++)
        {
            if(row[i]==0){
                cout<<i;
                for(int j=0;j<m;j++)
                {
                    cout<<"hi"<<i<<j;
                    matrix[j][i]=0;
                    cout<<"*"<<" ";
                }
            }
        }
        cout<<" hi2135"<<" ";
        for(int i=0;i<m;i++)
        {
            if(col[i]==0){
                for(int j=0;j<n;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
       
        
    }
};