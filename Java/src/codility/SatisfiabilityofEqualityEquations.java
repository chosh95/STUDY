package codility;

public class SatisfiabilityofEqualityEquations {
    class Solution {
        int[] p = new int[27];

        int find(int x){
            if(p[x] ==x) return x;
            return p[x] = find(p[x]);
        }

        public boolean equationsPossible(String[] equations) {
            for(int i=0;i<27;i++) p[i] = i;

            for(String str : equations) {
                int a = str.charAt(0) - 'a';
                int b = str.charAt(3) - 'a';
                if(str.charAt(1)=='=')
                    p[find(b)] = find(a);
            }

            for(String str : equations) {
                int a = str.charAt(0) - 'a';
                int b = str.charAt(3) - 'a';
                if(str.charAt(1)=='!' && find(a)==find(b)) return false;
            }

            return true;
        }
    }
}
