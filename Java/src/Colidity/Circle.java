package Colidity;

public class Circle {
    class Solution {
        public int solution(int inner, int outer, int[] points_x, int[] points_y) {
            int answer = 0;
            int minDist = inner * inner; // 최소 거리
            int maxDist = outer * outer; // 최대 거리

            for(int i = 0; i < points_x.length; i++){
                int curDist = 0;
                curDist += points_x[i] * points_x[i];
                curDist += points_y[i] * points_y[i];

                // 현재 거리가 최소, 최대 거리 사이일 때
                if(minDist < curDist && curDist < maxDist)
                    answer++;
            }

            return answer;
        }
    }
}
