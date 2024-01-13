class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> nums(26,0);
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            nums[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++)
        {
            int k=t[i]-'a';
            if(nums[k]!=0)nums[k]--;
        }
        for(int i=0;i<26;i++)
        {
            ans+=nums[i];
        }
        return ans;
        
    }
};