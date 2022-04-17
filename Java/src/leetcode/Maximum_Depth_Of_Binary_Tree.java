package leetcode;

public class Maximum_Depth_Of_Binary_Tree {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    private static int maxNum;

    public static void main(String[] args) {
        TreeNode t = new TreeNode(1, null, new TreeNode(2));
        System.out.println(maxDepth(t));
    }

    public static int maxDepth(TreeNode root) {
        dfs(root, 1);
        return maxNum;
    }

    public static void dfs(TreeNode cur, int curDepth) {
        if (cur == null) return;
        if (maxNum < curDepth) {
            maxNum = curDepth;
        }
        if (cur.left != null) {
            dfs(cur.left, curDepth + 1);
        }
        if (cur.right != null) {
            dfs(cur.right, curDepth + 1);
        }
    }
}
