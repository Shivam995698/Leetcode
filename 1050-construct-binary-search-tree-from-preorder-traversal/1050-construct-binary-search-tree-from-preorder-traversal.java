/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static TreeNode helper(int[] pre,int idx[],int ub[])
    {
        if(idx[0]==pre.length || pre[idx[0]]>ub[0])
        {
            return null;
        }
        TreeNode root = new TreeNode(pre[idx[0]++]);
        root.left = helper(pre,idx,new int[] {root.val});
        root.right = helper(pre,idx,ub);
        return root;
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        int idx[] = {0};
        int ub[] = {Integer.MAX_VALUE};
        return helper(preorder,idx,ub);
    }
}