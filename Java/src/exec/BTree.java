package exec;

import sun.reflect.generics.tree.Tree;

import java.util.LinkedList;
import java.util.Queue;

class TreeNode{
    int data;
    TreeNode leftChild, rightChild;

    public TreeNode(int data) {
        this.data = data;
        leftChild = rightChild = null;
    }
}

public class BTree {
    TreeNode root;

    public BTree() {
        root = null;
    }

    public void insert(int data){
        if(root==null)
            root = new TreeNode(data);
        else
            insert(root,data);
    }

    public void insert(TreeNode cur, int data){
        if(cur.data < data){
            if(cur.rightChild==null)
                cur.rightChild = new TreeNode(data);
            else
                insert(cur.rightChild,data);
        }
        else{
            if(cur.leftChild==null)
                cur.leftChild = new TreeNode(data);
            else
                insert(cur.leftChild,data);
        }
    }

    public void traverse(){
        System.out.println("traverse 시작");
        traverse(root);
        System.out.println("traverse 끝");
    }

    public void traverse(TreeNode cur){
        if(cur==null) return;
        System.out.print(cur.data + " - ");
        traverse(cur.leftChild);
        traverse(cur.rightChild);
    }

    public void delete(int data){
        delete(root,data);
    }

    public int findMin(TreeNode cur){
        if(cur.leftChild!=null)
            return findMin(cur.leftChild);
        return cur.data;
    }

    public TreeNode delete(TreeNode cur, int data){
        if(cur==null) return null;
        if(cur.data < data)
            cur.rightChild = delete(cur.rightChild, data);
        else if(cur.data > data)
            cur.leftChild = delete(cur.leftChild, data);
        else{
            if(cur.leftChild!=null && cur.rightChild!=null){
                int newData = findMin(cur.rightChild);
                cur.data = newData;
                cur.rightChild = delete(cur.rightChild,newData);
            }
            else if(cur.rightChild!=null)
                cur = cur.rightChild;
            else if(cur.leftChild != null)
                cur = cur.leftChild;
            else
                cur = null;
        }
        return cur;
    }

    public void doBfs(){
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        System.out.println("Bfs 순회 : ");
        while(!q.isEmpty()){
            TreeNode cur = q.poll();
            System.out.print(cur.data + " ");

            if(cur.leftChild!=null)
                q.add(cur.leftChild);
            if(cur.rightChild!=null)
                q.add(cur.rightChild);
        }
        System.out.println("\nBfs 순회 종료");
    }
}

class test1{
    public static void main(String[] args) {
        BTree tree = new BTree();
        tree.insert(5);
        tree.insert(2);
        tree.insert(6);
        tree.insert(7);
        tree.insert(3);
        tree.insert(8);
        tree.doBfs();
        tree.traverse();

        tree.delete(5);
        tree.traverse();

        tree.doBfs();
    }
}
