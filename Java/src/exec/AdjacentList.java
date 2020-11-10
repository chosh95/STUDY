package exec;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class AdjacentList {

    static class Point{
        int end;
        int cost;

        public Point(int end, int cost) {
            this.end = end;
            this.cost = cost;
        }
    }

    public static int bfs(ArrayList<ArrayList<Point>> list){
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(1,0));
        int visit[] = new int[list.size()+1];
        visit[1] = 0;

        int res = 0;
        while(!q.isEmpty()){
            Point cur = q.poll();

            for(Point point : list.get(cur.end)){
                if(visit[point.end]>visit[cur.end]+point.cost) continue;
                q.add(point);
                visit[point.end] = visit[cur.end] + point.cost;
            }
        }

        return visit[3];
    }

    public static void main(String[] args) {
        ArrayList<ArrayList<Point>> list = new ArrayList<ArrayList<Point>>();
        for(int i=0;i<10;i++)
            list.add(new ArrayList<Point>());

        list.get(1).add(new Point(2,3));
        list.get(2).add(new Point(3,5));

        System.out.println(bfs(list));
    }
}
