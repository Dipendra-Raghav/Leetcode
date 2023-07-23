class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0;
        int m=0;
        int e=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)s++;
            if(nums[i]==1)m++;
            if(nums[i]==2)e++;
        }
        s=s-1;
        m=m+s;
        e=e+m;
        cout<<s<<m<<e;
        
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]==0 && i<=s) || (nums[i]==1 && i>s) || (nums[i]==2 && i>m))
                continue;
            
            if(nums[i]==2)
            {
                swap(nums[i],nums[e]);
                e--;
                i--;
            }
            else if(nums[i]==1)
            {
                swap(nums[i],nums[m]);
                m--;
                i--;
            }
        }
    
        
    }
};