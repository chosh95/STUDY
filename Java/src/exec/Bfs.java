package exec;

import java.util.LinkedList;
import java.util.Queue;

public class Bfs {

    static class Point{
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    int[] dx = new int[]{0,1,-1,0};
    int[] dy = new int[]{-1,0,0,1};

    void doBfs(int a, int b, int[][] p, boolean[][] visit){
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(a, b));
        visit[a][b] = true;

        while(!q.isEmpty()){
            Point cur = q.poll();

            for(int i=0;i<4;i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if(nx < 0 || ny<0 || nx >= p.length || ny >= p[0].length) continue;
                if(p[nx][ny]==0 || visit[nx][ny]) continue;
                q.add(new Point(nx, ny));
                visit[nx][ny] = true;
            }
        }
    }
    public static void main(String[] args) {
        int[][] p = new int[][]{{1,0,0},{1,1,0},{0,0,1}};
        boolean[][] visit = new boolean[3][3];
        int res = 0;
        Bfs bfs = new Bfs();
        for(int i=0;i<p.length;i++){
            for(int j=0;j<p.length;j++){
                if(p[i][j]==1 && !visit[i][j]){
                    bfs.doBfs(i,j,p,visit);
                    res++;
                }
            }
        }

        System.out.println(res);
    }
}