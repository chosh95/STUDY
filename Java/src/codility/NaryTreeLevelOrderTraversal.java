package codility;

import java.util.LinkedList;
import java.util.List;

public class NaryTreeLevelOrderTraversal {

    class Node {
        public int val;
        public List<Node> children;

        public Node() {}

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }
    };

    class Solution {
        List<List<Integer>> res;

        public List<List<Integer>> levelOrder(Node root) {
            res = new LinkedList<>();
            traverse(root,0);
            return res;
        }

        public void traverse(Node cur, int level){
            if(cur==null) return;
            if(res.size()==level)
                res.add(new LinkedList<>());
            res.get(level).add(cur.val);
            for(int i=0;i<cur.children.size();i++){
                traverse(cur.children.get(i),level+1);
            }
        }
    }
}
