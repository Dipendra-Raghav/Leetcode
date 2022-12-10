class Solution {
public:
    #define mod 1000000007
    long long tsum;
    long long getSum(TreeNode* root)
    {
        if(root==NULL)return 0;
        return root->val+(getSum(root->left)+getSum(root->right));
    }
    long long solve(TreeNode* root,long long &mx)
    {
        if(root==NULL)return 0;
        long long sum1=root->val+solve(root->left,mx)+solve(root->right,mx);   
        long long ext=(sum1);
        long long ent=(tsum-sum1);
        long long ans=(ext*ent);
        mx= max(ans,mx);
        return sum1;
        
    }
    int maxProduct(TreeNode* root) {
        tsum=getSum(root);
        cout<<tsum;
        long long mx=LONG_MIN;
        solve(root,mx);
        return mx%mod;
    }
};