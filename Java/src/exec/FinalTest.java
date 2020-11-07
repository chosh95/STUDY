package exec;

public class FinalTest {


    public static void main(String[] args) {
        final StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("Hello");
        System.out.println(stringBuilder);
        stringBuilder.append(" World");
        System.out.println(stringBuilder);
        // stringBuilder = null; final이기 때문에 참조하는 객체 null로 변경 불가능 
    }
}
