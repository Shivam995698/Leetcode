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
    int maxi = INT_MIN;
    int solve(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int ans1 = max(0,solve(root->left));
        int ans2 = max(0,solve(root->right));
        int currSum = ans1+ans2+root->val;
        maxi = root->val+max(currSum,maxi);
        return maxi;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int sum = solve(root);
        return sum;
        
    }
};