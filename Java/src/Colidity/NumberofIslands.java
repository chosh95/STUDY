package Colidity;

import java.util.LinkedList;
import java.util.Queue;

public class NumberofIslands {
    class Solution {
        boolean visit[][];
        int[] dx = {-1,0,0,1};
        int[] dy = {0,-1,1,0};

        void bfs(int a, int b, char[][] grid){
            Queue<Point> q = new LinkedList<>();
            q.add(new Point(a,b));
            visit[a][b] = true;

            while(!q.isEmpty()){
                Point cur = q.poll();

                for(int i=0;i<4;i++){
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    if(nx<0 || ny<0 || nx>=grid.length || ny>=grid[0].length) continue;
                    if(visit[nx][ny] || grid[nx][ny] != '1') continue;
                    q.add(new Point(nx,ny));
                    visit[nx][ny] = true;
                }
            }

        }

        class Point{
            int x, y;
            public Point(int x, int y) {
                this.x = x;
                this.y = y;
            }
        }

        public int numIslands(char[][] grid) {
            visit= new boolean[grid.length][grid[0].length];

            int res = 0;
            for(int i=0;i<grid.length;i++){
                for(int j=0;j<grid[0].length;j++){
                    if(grid[i][j]=='1' && !visit[i][j]){
                        bfs(i,j,grid);
                        res++;
                    }
                }
            }
            return res;
        }
    }
}
