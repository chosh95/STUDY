package codility;

public class Jacob {
    class Solution {
        int solution(int X, int Y, int[] A) {
            int N = A.length;
            int result = -1;
            int nX = 0;
            int nY = 0;
            for (int i = 0; i < N; i++) {
                if (A[i] == X)
                    nX += 1;
                if (A[i] == Y)
                    nY += 1;
                if (nX == nY)
                    result = i;
            }
            return result;
        }
    }

}
