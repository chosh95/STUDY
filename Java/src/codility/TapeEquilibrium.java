package codility;

public class TapeEquilibrium {
    class Solution {
        public int solution(int[] A) {

            int[] p = new int[A.length];
            p[0] = A[0];
            for(int i=1;i<A.length;i++)
                p[i] = p[i-1] + A[i];

            int answer = 987654321;
            for(int i=0;i<p.length-1;i++)
                answer = Math.min(answer,Math.abs(p[p.length-1]-p[i]-p[i]));
            return answer;
        }
    }
}
