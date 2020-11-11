package nv;

import java.util.Stack;

public class ex {
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        st.push(1);
        st.push(2);

        for(Integer x : st)
            System.out.println(x);
    }
}
