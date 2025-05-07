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
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left,right)+1;
        return ans;
    }
    int getdiameter(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left = getdiameter(root->left);
        int right = getdiameter(root->right);
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        int ans = (leftheight+rightheight);
        return max(max(left,right),ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = getdiameter(root);
        return ans;
    }
};