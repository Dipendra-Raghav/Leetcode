class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int min=INT_MAX,index;
        int n=nums.size();
        long long pre[n];
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+nums[i];
        for(int i=0;i<nums.size();i++){
            int num1=pre[i]/(i+1);
            int num2;
            int x=(nums.size()-i-1);
            if(x==0)
                num2=0;
            else num2=(pre[n-1]-pre[i])/x;
            if(abs(num1-num2)<min){
                min=abs(num1-num2);
                index=i;
        }
      }
      return index;
    }
};