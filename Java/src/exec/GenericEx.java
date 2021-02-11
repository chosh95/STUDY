package exec;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.ReentrantLock;

public class GenericEx {
    static class GenericTest<T> {
        T data;

        //static T data2; // static 불가능 메서드는 가능
        void setData(T data) {
            this.data = data;
        }

        T getData() {
            return this.data;
        }
    }

    public static void main(String[] args) {
        List list = new ArrayList(); // raw 타입 선언
        list.add("String value"); // String 값 추가
        int a = (int) list.get(0); // int로 형 변환은 했지만 불가능

        GenericTest gt = new GenericTest(); //raw type
        gt.setData(123); // int로 넣고
        String data = (String) gt.getData(); //String으로 빼면 Compile 타임에는 괜찮음
        System.out.println(data); // Runtime에 ClassCastException 발생
    }
}
