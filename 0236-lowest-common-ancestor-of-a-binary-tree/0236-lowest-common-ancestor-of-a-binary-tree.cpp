/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    bool flag=true;
    bool chk(TreeNode* root, TreeNode* qu)
    {
        if(root==qu)return true;
        if(root==NULL)return false;
        bool a=chk(root->left,qu);
        bool b= chk(root->right, qu);
        return a || b;
    }
   
    bool solve(TreeNode* root, TreeNode* p,TreeNode* q)
    {
        if(root==NULL)return false;
        
        if(root==p)
        {
            if(chk(root,q))
            {
                ans=root;
               
                return true;
            }
            else
                return true;
        }
        else if(root==q)
        {
            if(chk(root,p))
            {
                ans=root;
                
                return true;
            }
            else
                return true;
        }
        bool a=solve(root->left,p,q);
       
        bool b=solve(root->right,p,q);
        if(a==true && b==true && flag )
        {
            ans=root;
            flag=false;
        }
        return a||b;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        solve(root, p,q);
        
        return ans;
        
    }
};