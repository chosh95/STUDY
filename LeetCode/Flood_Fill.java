package com.company.leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class Flood_Fill {
    class Node{
        int x,y;

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    class Solution {
        public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
            int curColor = image[sr][sc];
            Queue<Node> q = new LinkedList<>();
            q.add(new Node(sr,sc));
            boolean[][] visit = new boolean[image.length][image[0].length];
            visit[sr][sc] = true;
            image[sr][sc] = newColor;
            Integer[] dx = {-1,0,0,1};
            Integer[] dy = {0,-1,1,0};
            while(!q.isEmpty()){
                Node cur = q.poll();

                for(int i=0;i<4;i++){
                    int nx = cur.getX() + dx[i];
                    int ny = cur.getY() + dy[i];
                    if(nx<0 || ny<0 || nx>=image.length || ny>=image[0].length) continue;
                    if(visit[nx][ny]) continue;
                    if(image[nx][ny] != curColor) continue;
                    visit[nx][ny] = true;
                    image[nx][ny] = newColor;
                    q.add(new Node(nx,ny));
                }
            }
            return image;
        }
    }
}


