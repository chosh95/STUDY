package Colidity;

import java.util.Stack;

public class Nesting {
    public int solution(String S) {
        Stack<Character> st = new Stack<>();

        for(int i=0;i<S.length();i++){
            if(S.charAt(i)=='(') st.push(S.charAt(i));
            else if(st.isEmpty()) return 0;
            else st.pop();
        }

        if(st.empty()) return 1;
        return 0;
    }
}

class test{
    public static void main(String[] args) {
        Nesting solution1 = new Nesting();
        System.out.println(solution1.solution("()"));
    }
}
