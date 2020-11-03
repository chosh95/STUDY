package Colidity;

public class MaxCounters {
    class Solution {
        public int[] solution(int N, int[] A) {
            int res[] = new int[N];
            int curMax = 0, curMin = 0;
            for(int i : A){
                if(i==N+1) curMin = curMax;
                else{
                    if(res[i-1] < curMin) res[i-1] = curMin + 1;
                    else res[i-1]++;
                    curMax = Math.max(curMax,res[i-1]);
                }
            }

            for(int i=0;i<N;i++)
                if(res[i]<curMin) res[i] = curMin;
            return res;
        }
    }

}
