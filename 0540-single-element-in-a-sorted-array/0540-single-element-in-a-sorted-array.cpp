class Solution {
public:
    int solve(vector<int> &nums)
    {
        int i=0;
        int j=nums.size()-1;
         if(j==0)return nums[0];
        while(i<=j)
        {
            int mid=(i+j)/2;
            if((mid==0 && nums[mid]!=nums[mid+1]) || (mid==nums.size()-1 && nums[mid]!=nums[mid-1]) ||(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1] ))return nums[mid];
            else if(mid%2==0)
            {
                if(nums[mid+1]==nums[mid])i=mid+1;
                else
                    j=mid-1;
            }
            else
            {
                if(nums[mid-1]==nums[mid])i=mid+1;
                else
                    j=mid-1;
                
            }
            
        }
        return 1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        return solve(nums);
        
    }
};