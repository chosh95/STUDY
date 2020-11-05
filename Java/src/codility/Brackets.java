package codility;

import java.util.Stack;

public class Brackets {
    class Solution {
        public int solution(String S) {
            Stack<Character> st = new Stack<>();
            for(int i=0;i<S.length();i++){
                if(S.charAt(i) == '(' || S.charAt(i) == '{' || S.charAt(i) == '[')
                    st.push(S.charAt(i));
                else if(st.empty()) return 0;
                else if(S.charAt(i) == ')' && st.peek()=='(') st.pop();
                else if(S.charAt(i) == '}' && st.peek()=='{') st.pop();
                else if(S.charAt(i) == ']' && st.peek()=='[') st.pop();
                else return 0;
            }
            if(!st.empty()) return 0;
            return 1;
        }
    }
}
