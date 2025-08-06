class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL)
        {
            return ans;
        }
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int>temp;
            for(int i =0;i<n;i++){
                TreeNode* front = q.front();
                q.pop();
                temp.push_back(front->val);
                if(front->left!=NULL)
                {
                    q.push(front->left);
                }
                if(front->right !=NULL)
                {
                    q.push(front->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};