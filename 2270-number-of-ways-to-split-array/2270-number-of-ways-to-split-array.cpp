class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> left(n);
        vector<long long> right(n);
        left[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1]+nums[i];
        }
        right[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1]+nums[i+1];
        }
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            if(left[i]>=right[i])cnt++;
        }
        return cnt;
        
    }
};