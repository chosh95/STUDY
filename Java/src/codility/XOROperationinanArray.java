package codility;

public class XOROperationinanArray {
    class Solution {
        public int xorOperation(int n, int start) {
            int cur = start;
            for(int i = 0, x = start*2; i < n; i++, x += 2){
                cur ^= x;
            }
            return cur;
        }
    }
}
