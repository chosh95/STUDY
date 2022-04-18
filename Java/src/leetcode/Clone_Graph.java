package leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new ArrayList<>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<>();
    }

    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

public class Clone_Graph {
    public Node cloneGraph(Node node) {
        if (node == null) return null;

        Node[] visit = new Node[101];
        Arrays.fill(visit, null);
        return dfs(new Node(node.val), node, visit);
    }

    public Node dfs(Node cur, Node origin, Node[] visit) {
        if (origin == null) return null;
        visit[origin.val] = cur;

        for (Node iNode : origin.neighbors) {
            if (visit[iNode.val] == null) {
                Node newNode = new Node(iNode.val);
                cur.neighbors.add(newNode);
                dfs(newNode, iNode, visit);
            } else {
                cur.neighbors.add(visit[iNode.val]);
            }
        }
        return cur;
    }
}
