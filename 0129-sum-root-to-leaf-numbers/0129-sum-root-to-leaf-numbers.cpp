/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    void solve(TreeNode* node,int sum,int k)
    {
        if(node==NULL)return;
        if(node->left==NULL && node->right==NULL)
        {
            sum=sum*10+node->val;
            ans+=sum;
            return ;
        }
        sum=sum*10+node->val;
        solve(node->left,sum,k+1);
        solve(node->right,sum,k+1);
        return ;
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0,0);
        return ans;
    }
};