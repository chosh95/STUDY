package Colidity;

import java.util.HashMap;
import java.util.Map;

public class Distinct {
    class Solution {
        public int solution(int[] A) {
            Map<Integer, Integer> m = new HashMap<>();

            for(int i : A){
                if(m.containsKey(i)) continue;
                m.put(i,1);
            }

            return m.size();
        }
    }
}
