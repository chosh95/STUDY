package exec;

public class Foo {
    private Node cur;
    private int size;

    class Node{
        int data;
        Node nextNode;

        public Node(int data) {
            this.data = data;
            this.nextNode = null;
        }
    }

    public Foo(int data) {
        this.cur = new Node(data);
        size = 1;
    }

    public int get(){
        Node next = cur.nextNode;
        int returnData = cur.data;
        size--;
        cur = next;
        return returnData;
    }

    public Node getCur() {
        return cur;
    }

    public int getSize() {
        return size;
    }
}

class test{
    public static void main(String[] args) {
        Foo foo = new Foo(1);
        System.out.println(foo.get());
        System.out.println(foo.getSize());
        System.out.println(foo.get());
    }
}
