package programmers;

import java.util.Arrays;
import java.util.Comparator;

public class 여행경로 {
    static class Solution {
        public String[] solution(String[][] tickets) {
            String[] answer = {};
            Arrays.sort(tickets, new Comparator<String[]>() {
                @Override
                public int compare(String[] o1, String[] o2) {
                    if(o1[0].compareTo(o2[0])==0)
                        return o1[1].compareTo(o2[1]);
                    return o1[0].compareTo(o2[0]);
                }
            });


            return answer;
        }
    }

}

class test12{
    public static void main(String[] args) {
        여행경로.Solution s = new 여행경로.Solution();
        s.solution(new String[][]{{"abc","bcd"},{"abc","daa"}});
    }
}
