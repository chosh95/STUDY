package Colidity;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class PathSumII {
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
        List<List<Integer>> res = new ArrayList<>();

        void find(TreeNode cur, List<Integer> list, int sum, int target){
            if(cur==null) return;
            if(cur.left==null && cur.right==null){
                if(sum==target) res.add(new ArrayList<>(list));
                return;
            }

            if(cur.left!=null){
                list.add(cur.left.val);
                find(cur.left,list,sum+cur.left.val,target);
                list.remove(list.size()-1);
            }

            if(cur.right!=null) {
                list.add(cur.right.val);
                find(cur.right, list, sum + cur.right.val, target);
                list.remove(list.size()-1);
            }
        }

        public List<List<Integer>> pathSum(TreeNode root, int sum) {
            List<Integer> path = new ArrayList<>();
            if(root==null) return res;
            path.add(root.val);
            find(root, path,root.val, sum);
            return res;
        }
    }
}
