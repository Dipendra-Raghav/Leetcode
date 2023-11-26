class Solution {
public:
    void sortRows(vector<vector<int>>& matrix) {
    // Iterate through each row and sort it in reverse order
    for (vector<int>& row : matrix) {
        sort(row.rbegin(), row.rend());
    }
}
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            int prev=0;
            for(int j=0;j<n;j++)
            {
                if(matrix[j][i]==1 && prev!=0)
                {
                    matrix[j][i]=prev+1;
                    prev++;
                }
                else
                {
                    matrix[j][i]=matrix[j][i]==1 ? 1: 0;
                    prev=matrix[j][i];
                }
            }
        }
        int mx=0;
        sortRows(matrix);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int k=matrix[i][j]*(j+1);
                mx=max(mx,k);
            }
            
        }
        return mx;
        
        
    }
};