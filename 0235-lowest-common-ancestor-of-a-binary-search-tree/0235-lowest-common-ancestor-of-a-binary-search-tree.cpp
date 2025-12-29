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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root== NULL)
        {
            return NULL;
        }
        if(root->val>p->val && root->val>q->val)
        {
            TreeNode* leftans = lowestCommonAncestor(root->left,p,q);
            return leftans;
        }
        if(root->val<p->val && root->val<q->val)
        {
            TreeNode* rightans = lowestCommonAncestor(root->right,p,q);
            return rightans;
        }
        if(root->left<p && root->right>q)
        {
            return root;
        }
        if(root->left>p && root<q)
        {
            return root;
        }
        return root;
    }
};