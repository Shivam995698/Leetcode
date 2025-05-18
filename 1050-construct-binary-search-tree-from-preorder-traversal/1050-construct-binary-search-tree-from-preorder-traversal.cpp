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
    int search(vector<int>inorder,int element)
    {
        int pos = 0;
        for(int i =0;i<inorder.size();i++)
        {
            if(inorder[i]==element)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>preorder,vector<int>inorder,int &preIndex,int InorderStart,int InorderEnd,int n)
    {
        //base case 
        if(preIndex>=n || InorderStart>InorderEnd)
        {
            return NULL;
        }
        int element = preorder[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(element);
        int position = search(inorder,element);
        root->left = solve(preorder,inorder,preIndex,InorderStart,position-1,n);
        root->right = solve(preorder,inorder,preIndex,position+1,InorderEnd,n);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>Inorder;
        int n = preorder.size();
        for(int i =0;i<n;i++)
        {
            Inorder.push_back(preorder[i]);
        }
        sort(Inorder.begin(),Inorder.end());
        int preIndex = 0;
        int InorderStart = 0;
        int InorderEnd = n-1;
        TreeNode* ans = solve(preorder,Inorder,preIndex,InorderStart,InorderEnd,n);
        return ans;
    }
};