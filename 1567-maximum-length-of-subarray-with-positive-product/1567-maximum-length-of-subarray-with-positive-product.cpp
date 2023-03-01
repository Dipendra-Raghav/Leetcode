class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans=0;
        int cnt=0;
        int x=0;
        int flag=0;
        int chk=0;
        int y=0;
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]<0)
           {
               y=k;
               cnt++;
               if(flag==0)
               {
                   flag=1;
                   x=k;
               }
               
               
           }
           if(nums[i]==0)
            {
                
                if(chk!=0)
                {
                    chk=chk-1;
                    cout<<x<<" "<<y<<" "<<chk<<" ";
                    if(cnt%2==0)
                    {
                        ans=max(ans,chk+1);
                    }
                    else
                    {
                        int z=x>=(chk-y)?y:chk-x;
                        ans=max(ans,z);
                    }
                flag=0;
                k=0;
                cnt=0;
                chk=0;
                }
               
               
                   continue;
               
                
            }
            chk++;
            k++;
        }
        if(chk!=0)
        {
            chk=chk-1;
            cout<<x<<" "<<y<<" "<<chk<<" "<<cnt;
            if(cnt%2==0)
            {
                ans=max(ans,chk+1);
            }
            else
            {
                int z=x>=(chk-y)?y:chk-x;
                ans=max(ans,z);
            }
        }
        return ans;
        
    }
};