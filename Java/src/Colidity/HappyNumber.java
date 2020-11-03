package Colidity;

import java.util.HashMap;
import java.util.Map;

public class HappyNumber {
    class Solution {
        public boolean isHappy(int n) {
            if(n==1) return true;

            Map<Integer,Integer> m = new HashMap<>();
            m.put(n,1);
            String cur = Integer.toString(n);
            while(true){
                int next = 0;
                for(char x : cur.toCharArray())
                    next += (x -'0')*(x-'0');
                if(m.containsKey(next)) return false;
                else m.put(next,1);
                if(next==1) return true;
                cur = Integer.toString(next);
            }
        }
    }

}