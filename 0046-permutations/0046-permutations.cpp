class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &res,vector<int> ans)
    {
        if(ans.size()==nums.size())
        {
            res.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            //include
            if(nums[i]!=INT_MIN)
            {
                ans.push_back(nums[i]);
                int t=nums[i];
                nums[i]=INT_MIN;
                solve(nums,res,ans);
                ans.pop_back();
                nums[i]=t;
            }
           
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //include and exclude calls
        vector<vector<int>> res;
        vector<int> ans;
        solve(nums,res,ans);
        return res;
    }
};