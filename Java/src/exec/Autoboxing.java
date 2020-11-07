package exec;

public class Autoboxing {
    public static void main(String[] args) {
        int b = 123;
        Integer a = new Integer(b);

        Integer c = new Integer(1);
        int d = c; // auto-unboxing
        int e = c.intValue();
    }
}
