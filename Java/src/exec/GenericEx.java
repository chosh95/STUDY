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
        GenericTest gt = new GenericTest();
        gt.setData(123);
        String data = (String)gt.getData();
        System.out.println(data);
    }
}
