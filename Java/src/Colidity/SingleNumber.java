package Colidity;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class SingleNumber {
    class Solution {
        public int singleNumber(int[] nums) {
            Map<Integer,Integer> m = new HashMap<>();
            for(int x : nums){
                if(m.containsKey(x)) m.remove(x);
                else m.putIfAbsent(x,1);
            }
            for(Integer x : m.keySet())
                return x;
            return 0;
        }
    }
}
