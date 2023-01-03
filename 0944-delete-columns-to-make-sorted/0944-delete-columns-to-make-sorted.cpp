class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        int chk=0;
        if(strs.size()==1)return 0;
        for(int i=0;i<strs[0].size();i++)
        {
            for(int j=1;j<strs.size();j++)
            {
                chk=strs[j][i]-strs[j-1][i];
                if(chk<0)
                {
                    ans++;
                    break;
                }
                
            }
        }
        return ans;
        
    }
};