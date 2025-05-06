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
    int Height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftans = Height(root->left);
        int rightans = Height(root->right);
        return max(leftans,rightans)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);
        int diff = abs(leftHeight - rightHeight);
        bool option1 = diff<=1;
        bool option2 = isBalanced(root->left);
        bool option3  = isBalanced(root->right);
        if(option1 && option2 && option3)
        {
            return true;
        }
        else{
            return false;
        }
    }
};