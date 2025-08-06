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
    int maxSum = INT_MIN;
    int SumOfPath(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftans =  max(0,SumOfPath(root->left));
        int rightans = max(0,SumOfPath(root->right));
        int currsum =  root->val + leftans + rightans;
        maxSum = max(maxSum,currsum);
        return root->val + max(leftans,rightans);
    
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
        {
            return NULL;
        }
        int anas =SumOfPath(root);
        return maxSum;

    }
};