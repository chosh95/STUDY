package Colidity;

import java.util.Arrays;

public class MinMaxDivision {
    class Solution {
        public boolean isPossible(int mid, int K, int[] A){
            int cnt = 1, cur = 0, N = A.length;
            for(int i=0;i<N;i++){
                cur += A[i];
                if(cur>mid){
                    cnt++;
                    cur = A[i];
                }
                if(cnt>K) return false;
            }
            return true;
        }

        public int solution(int K, int M, int[] A) {
            //int lo = Arrays.stream(A).max().getAsInt(), hi = Arrays.stream(A).sum();
            int lo = 0, hi = 0;
            for(int x : A){
                lo = Math.max(lo,x);
                hi += x;
            }
            int res = hi;

            while(lo<=hi){
                int mid = (lo+hi) / 2;
                if(isPossible(mid,K, A)){
                    hi = mid-1;
                    res = mid;
                }
                else
                    lo = mid+1;
            }
            return res;
        }
    }
}
