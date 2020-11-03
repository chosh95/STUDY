package Colidity;

import java.util.Arrays;
import java.util.Comparator;

public class NumberOfDiscIntersections {
    public static void main(String[] args) {
        Solution2 s = new Solution2();
        System.out.println(s.solution(new int[]{1, 5, 2, 1, 4, 0}));
    }
}

class Solution2 {
    public int solution(int[] A) {
        class Point{
            long x, y;

            public Point(long x, long y) {
                this.x = x;
                this.y = y;
            }
        }

        Point[] p = new Point[A.length];

        for(int i = 0; i<A.length; i++)
            p[i] = new Point(i - (long)A[i], i + (long)A[i]);

        Arrays.sort(p, new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                if(o1.x < o2.x) return -1;
                else if(o1.x==o2.x){
                    if(o1.y<o2.y) return -1;
                    else return 1;
                }
                return 1;
            }
        });

        int cnt = 0;
        int N = A.length;
        for(int i=0;i<N-1; i++){
            for(int j=i+1;j<N; j++){
                if(cnt > 10000000) return -1;
                if(p[i].y >= p[j].x) cnt++;
                else break;
            }
        }

        return cnt;
    }
}