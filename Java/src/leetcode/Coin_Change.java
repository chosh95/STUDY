package leetcode;

import javafx.util.Pair;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class Coin_Change {
    public static void main(String[] args) {
        System.out.println(coinChange(new int[]{1, 2147483647}, 2));
    }

    public static int coinChange(int[] coins, int amount) {
        if (amount == 0) return 0;

        Queue<Integer> q = new LinkedList<>();
        Map<Integer, Integer> map = new HashMap<>();

        for (int coin : coins) {
            q.add(coin);
            map.put(coin, 1);
        }

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int coin : coins) {
                int next = cur + coin;
                if (next > amount) continue;
                if (map.containsKey(next) && map.get(next) <= map.get(cur) + 1) continue;
                if (next == amount) return map.get(cur) + 1;
                map.put(next, map.get(cur) + 1);
                q.add(coin + cur);
            }
        }

        return -1;
    }
}
