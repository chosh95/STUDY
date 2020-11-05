package programmers;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class 단어변환 {
    class Solution {

        public int solution(String begin, String target, String[] words) {
            int answer = 0;
            Map<String,Integer> map = new HashMap<>();
            map.putIfAbsent(begin,0);
            Queue<Point> q = new LinkedList<>();
            q.add(new Point(begin,0));

            while(!q.isEmpty()){
                Point cur = q.poll();

                if(cur.str.equals(target))
                    return cur.cnt;

                for(String x : words){
                    int diff = 0;
                    for(int i=0;i<x.length();i++)
                        if(x.charAt(i)!=cur.str.charAt(i)) diff++;
                    if(diff==1) {
                        if(map.containsKey(x)) continue;
                        map.putIfAbsent(x,cur.cnt+1);
                        q.add(new Point(x,cur.cnt+1));
                    }
                }
            }
            return answer;
        }

        class Point{
            String str;
            Integer cnt;

            public Point(String str, Integer cnt) {
                this.str = str;
                this.cnt = cnt;
            }
        }
    }
}
