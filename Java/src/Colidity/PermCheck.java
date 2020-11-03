package Colidity;

public class PermCheck {
    class Solution {
        boolean p[] = new boolean[100001];
        public int solution(int[] A) {

            int cnt = 0, maxNum = 0;
            for(int i : A){
                if(i>100000) return 0;
                if(p[i]) return 0;
                p[i] = true;
                cnt++;
                maxNum = Math.max(maxNum,i);
            }
            if(maxNum!=cnt) return 0;
            return 1;
        }
    }
}
