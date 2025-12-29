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
    bool solve(TreeNode* root,long long int ub,long long int lb)
    {
        if(root== NULL)
        {
            return true;
        }
        bool ans1 = (root->val<ub);
        bool ans2 = (root->val>lb);
        bool ans3 = solve(root->left,root->val,lb);
        bool ans4 = solve(root->right,ub,root->val);
        return ans1 && ans2 && ans3 && ans4;

    }
    bool isValidBST(TreeNode* root) {
        long long int upperBound = 2147485648;
        long long int lowerBound = -2147485648;
        bool ans = solve(root,upperBound,lowerBound);
        return ans; 
    }
};