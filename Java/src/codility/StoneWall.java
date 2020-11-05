package codility;

import java.util.Stack;

public class StoneWall {
    class Solution {
        public int solution(int[] H) {
            Stack<Integer> st = new Stack<>();

            int answer = 0;
            for(int i=0;i<H.length;i++){
                while(!st.empty() && st.peek() > H[i])
                    st.pop();
                if(st.empty() || st.peek() < H[i]) {
                    st.push(H[i]);
                    answer++;
                }
            }

            return answer;
        }
    }

}
