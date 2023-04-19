class Solution {
public:
    int mx=0;
    int solve(TreeNode* root,bool flag)
    {
        if(root==NULL)return 0;
        int left=1+solve(root->left,true);
        int right=1+solve(root->right,false);
        mx=max(mx,max(left,right));
        return flag==true?right:left;

    }
    int longestZigZag(TreeNode* root) {
        solve(root,true);
        return mx-1;
    }
};