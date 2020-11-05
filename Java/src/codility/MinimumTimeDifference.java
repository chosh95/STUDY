package codility;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class MinimumTimeDifference {
    static class Solution {
        public int findMinDifference(List<String> timePoints) {
            List<Integer> list = new ArrayList<>();

            for(String str : timePoints){
                int h = Integer.parseInt(str.substring(0,2));
                int m = Integer.parseInt(str.substring(3,5));
                list.add(m+h*60);
            }

            Collections.sort(list);

            int res = 1439;
            res = Math.min(res ,list.get(0)+1440 - list.get(list.size()-1));
            for(int i =0;i<list.size()-1;i++) {
                res = Math.min(res, Math.abs(list.get(i) - list.get(i + 1)));
                res = Math.min(res, Math.abs(list.get(i) + 1440 - list.get(i + 1)));
            }

            return res;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.findMinDifference(Arrays.asList("00:00","04:00","22:00")));
    }
}
