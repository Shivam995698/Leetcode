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
    bool solve(TreeNode* T1,TreeNode* T2)
    {
        if(T1 == NULL && T2 == NULL)
        {
            return true;
        }
        if(T1==NULL || T2 == NULL)
        {
            return false;
        }
        return (T1->val == T2->val) && solve(T1->left,T2->right) && solve(T1->right , T2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        return solve(root->left,root->right);
    }
};