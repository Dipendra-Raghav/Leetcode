class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,int i,vector<int> res)
    {
        ans.push_back(res);
        
        for(int j=i;j<nums.size();j++)
        {
          
            
            if(j>i && nums[j]==nums[j-1])
            {
                continue;
            }
                res.push_back(nums[j]);
                solve(nums,j+1,res);
                res.pop_back(); 
           
        }
         
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<int> res;
        
        solve(nums,0,res);
        return ans;
        
    }
};