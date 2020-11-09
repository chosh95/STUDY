package exec;


import java.util.Hashtable;

public class LinkedList {
    
    static class Node{
        int data;
        Node nextNode;

        public Node(int data) {
            this.data = data;
            this.nextNode = null;
        }
    }

    Node root;

    public LinkedList() {
        root = null;
    }

    public void print(){
        print(root);
        System.out.println();
    }

    public void print(Node cur){
        System.out.print(cur.data+" ");
        if(cur.nextNode!=null)
            print(cur.nextNode);
    }

    public void insert(int data){
        if(root == null)
            root = new Node(data);
        else
            insert(data,root);
    }

    public Node insert(int data, Node cur){
        if(cur.nextNode!=null)
            return insert(data,cur.nextNode);
        cur.nextNode = new Node(data);
        return cur;
    }

    public void deleteNode(int data){
        if(root.data==data)
            root = root.nextNode;
        else deleteNode(root,data);
    }

    public void deleteNode(Node cur, int data){
        if(cur.nextNode.data==data){
            Node nextNode = cur.nextNode.nextNode;
            cur.nextNode = null;
            cur.nextNode = nextNode;
            return;
        }
        deleteNode(cur.nextNode,data);
    }

    public void reverse(){
        reverse(root);
    }

    public void reverseIter(){
        Node cur = root;
        Node prev = null, next = null;

        while(cur.nextNode!=null){
            next = cur.nextNode;
            cur.nextNode = prev;
            prev = cur;
            cur = next;
        }

        root = cur;
        cur.nextNode = prev;
    }
    public Node reverse(Node cur){
        if(cur.nextNode != null){
            Node nextNode = reverse(cur.nextNode);
            nextNode.nextNode = cur;
            cur.nextNode = null;
            return cur;
        }
        this.root = cur;
        return cur;
    }


    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.insert(1);
        list.insert(2);
        list.insert(3);
        list.insert(4);
        list.reverse();
        list.print();
        list.deleteNode(4);
        list.print();
        list.reverse();
        list.print();
        list.reverseIter();
        list.print();

    }
}