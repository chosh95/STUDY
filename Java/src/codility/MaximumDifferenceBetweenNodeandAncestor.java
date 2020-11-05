package codility;

public class MaximumDifferenceBetweenNodeandAncestor {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
        }
    }

    class Solution {

        int dfs(TreeNode cur, int mn, int mx){
           if(cur==null) return mx-mn;
           mx = Math.max(cur.val,mx);
           mn = Math.min(cur.val,mn);
           return Math.max(dfs(cur.left,mn,mx),dfs(cur.right,mn,mx));
        }

        public int maxAncestorDiff(TreeNode root) {
            return dfs(root,root.val,root.val);
        }
    }
}
