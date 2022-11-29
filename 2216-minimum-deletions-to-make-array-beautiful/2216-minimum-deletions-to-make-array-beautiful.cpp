class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<int> st;
        st.push(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(st.size()%2!=0)
            {
                if(st.top()==nums[i])
                {
                    continue;
                }
                else
                {
                    st.push(nums[i]);
                }
            }
            else
            {
                st.push(nums[i]);
            }
        }
        int n=nums.size()-st.size();
        int ans=st.size()%2==0? n:n+1;   
        return ans;
    }
};