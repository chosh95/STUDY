package codility;

public class SameTree {
    static class TreeNode {
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
        boolean isValid(TreeNode p, TreeNode q){
            if(p==null && q==null) return true;
            if(p == null || q == null) return false;
            if(p.val != q.val) return false;
            if(isValid(p.left,q.left) && isValid(p.right,q.right))
                return true;
            return false;
        }

        public boolean isSameTree(TreeNode p, TreeNode q) {
            return isValid(p,q);
        }
    }
}
