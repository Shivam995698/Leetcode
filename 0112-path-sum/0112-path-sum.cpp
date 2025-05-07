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
    bool Solve(TreeNode* root,int target,int sum)
    {
        if(root == NULL)
        {
            return false;
        }
        sum+=root->val;
        if(root->left == NULL && root->right == NULL)
        {
            if(sum==target)
            {
                return true;
            }
            else{
                return false;
            }
        }
        int leftans = Solve(root->left,target,sum);
        int rightans =Solve(root->right,target,sum);
        return (leftans || rightans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = Solve(root,targetSum,sum);
        return ans;
    }
};