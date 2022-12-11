
class Solution {
public: 
    int solve(TreeNode* root,int &k)
    {
        if(root==NULL)return 0;
        int left=solve(root->left,k);
        int right=solve(root->right,k);
        
        if(root->left==NULL && root->right==NULL)
        {
            int p=right+left+root->val;
            k=k<p?p:k;
           
            return root->val;
        }
        
        if(left>=right)
        {
            
            int p=right+left+root->val;
            k=k<p?p:k;
            int ans= left+root->val>=root->val ?left+root->val : root-> val;
            k=k<ans?ans:k;
            return ans;
            
        }
            int p=right+left+root->val;
            k=k<p?p:k;
       
            int ans= right+root->val>=root->val ?right+root->val : root-> val;
        k=k<ans?ans:k;
        return ans; 
        
        
    }
    int maxPathSum(TreeNode* root) {
        int k=INT_MIN;
       int ans= solve(root,k);
        return k>=ans ? k : ans;
        
        
        
    }
};
