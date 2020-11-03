package Colidity;

import java.util.HashMap;
import java.util.Map;

public class OddOccurrencesInArray {
    class Solution {
        public int solution(int[] A) {
            Map<Integer,Integer> map = new HashMap<>();
            for(int i : A) {
                if (!map.containsKey(i))
                    map.put(i, 1);
                else
                    map.put(i, map.get(i) + 1);
            }
            for(Integer x : map.keySet())
                if(map.get(x)%2==1) return x;
            return 0;
        }
    }
}
