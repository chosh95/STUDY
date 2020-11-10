package exec;

public class GenericEx {
    static class GenericTest<T> {
        T data;
//         static T data2; // static 불가능 메서드는 가능
        void setData(T data){
            this.data = data;
        }

        T getData(){
            return this.data;
        }
    }

    public static void main(String[] args) {
        GenericTest gt = new GenericTest(); //raw type
        gt.setData(123); // int로 넣고
        String data = (String)gt.getData(); //String으로 빼면 Compile 타임에는 괜찮음
        System.out.println(data); // Runtime에 ClassCastException 발생
    }
}
