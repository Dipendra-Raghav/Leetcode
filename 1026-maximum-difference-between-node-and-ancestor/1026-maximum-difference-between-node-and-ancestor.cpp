class Solution {
public:
    int solve(TreeNode* root,int mx,int mn)
    {
        if(root==NULL)
            return abs(mx-mn);
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        int left=solve(root->left,mx,mn);
        int right=solve(root->right,mx,mn);
        return max(left,right);
    }
    int maxAncestorDiff(TreeNode* root) {
        int mx = INT_MIN;
        int mn = INT_MAX;
        return solve(root,mx,mn);
        
    }
};
