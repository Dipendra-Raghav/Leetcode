class Solution {
public:
    double solve(double x, int n)
    {
        if(n==0)
        return 1;
        if(n==1)return x;
        double ans=solve(x,n/2);
        if(n%2==0)
            return ans*ans;
        else
            return x* ans* ans;
        
    }
    double myPow(double x, int n) {
        if(n>0)
           return solve(x,n);
        else 
           return solve(1/x,abs(n));
        
    }
};