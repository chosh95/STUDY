package codility;

import java.util.ArrayList;
import java.util.List;

public class TheKWeakestRowsinaMatrix {
    class Solution {
        public int[] kWeakestRows(int[][] mat, int k) {
            List<Point> list = new ArrayList<>();

            for(int i=0;i<mat.length;i++){
                int sum = 0;
                for(int j=0;j<mat[0].length;j++)
                    sum += mat[i][j];
                list.add(new Point(i,sum));
            }

            list.sort((a, b) ->{
               if(a.cnt < b.cnt) return -1;
               else if(a.cnt > b.cnt) return 1;
               else{
                   if(a.row<b.row) return -1;
                   else return 1;
               }
            });

            int p[] = new int[k];
            for(int i=0;i<k;i++){
                p[i] = list.get(i).row;
            }

            return p;
        }

        class Point{
            int row,cnt;

            public Point(int row, int cnt) {
                this.row = row;
                this.cnt = cnt;
            }

        }
    }
}
