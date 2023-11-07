class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx=0;
        for(int i=0;i<arr.size();i++)mx=max(mx,arr[i]);
        if(k>arr.size())return mx;
        int t=0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[0]>arr[i])
            {
                t++;
            }
            else
            {
                swap(arr[0],arr[i]);
                t=1;
            }
            if(t==k)return arr[0];
        }
        return mx;
    }
};