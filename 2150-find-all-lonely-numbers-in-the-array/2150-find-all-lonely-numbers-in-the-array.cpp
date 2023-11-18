class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        if(nums.size()==1)
        {
            ans.push_back(nums[0]);
            return ans;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                if(nums[i+1]==nums[i] || nums[i]+1==nums[i+1])
                {
                    i+1;
                    continue;
                }
                else
                ans.push_back(nums[i]);
            }
            else if(i==nums.size()-1)
            {
                if(nums[i-1]==nums[i] || nums[i]-1==nums[i-1])
                {
                    break;
                }
                else
                ans.push_back(nums[i]);
            }
            else
            {
                cout<<i<<" ";
                if(nums[i+1]==nums[i] || nums[i]+1==nums[i+1])
                {
                    i+1;
                    continue;
                }
                if(nums[i-1]==nums[i] || nums[i]-1==nums[i-1])
                {
                    continue;
                }
                else
                ans.push_back(nums[i]);
            } 
        }
        return ans;
        
        
        
    }
};