class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=gas.size();
        int ans=0;
        int amt=0;
        int fnt=0;
        int cnt=0;
        if(n==1)
        {
            if(gas[0]-cost[0]>=0)return 0;
            else return -1;
        }
        for(int i=0;i<n;i=(i+1)%n)
        {
            if(cnt==2*n)break;
            if(fnt==0)ans=i;
            cout<<i<<" ";
            if(i==ans && fnt==1)return i;
            
            if(amt+gas[i]>=cost[i])
            {
                amt+=gas[i];
                amt-=cost[i];
            }
            else if(amt+gas[i]<cost[i])
            {
                amt=0;
                ans=(i+1)%n;
                fnt=0;
            }
            
            if(i==ans)fnt=1;
            cnt++;
        }
        return -1;
        
    }
};