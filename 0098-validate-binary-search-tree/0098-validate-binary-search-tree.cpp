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
    bool solve(long long int ub, long long int lb,TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }
        bool upper = (root->val < ub);
        bool lower = (root->val > lb);
        bool leftans = solve(root->val,lb,root->left);
        bool rightans = solve(ub,root->val,root->right);
        if((upper)&&(lower)&&(leftans)&&(rightans))
        {
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        long long int upperBound = 2147485648;
        long long int lowerBound = -2147485648;
        bool ans = solve(upperBound,lowerBound,root);
        return ans;
    }
};