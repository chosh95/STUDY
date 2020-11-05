package codility;

public class BinaryGap {

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.solution(1041));
    }
}

class Solution {
    public int solution(int N) {
        int cur = 0, cnt = 0, res = 0;
        boolean isOne = false;
        while(N!=0){
            cur = N % 2;
            if(cur==1){
                if(!isOne) isOne = true;
                else res = Math.max(res,cnt);
                cnt = 0;
            }
            else cnt++;
            N /= 2;
        }
        return res;
    }
}