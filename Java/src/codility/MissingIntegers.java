package codility;

public class MissingIntegers {
}

class MissingIntegersSolution {
    public int solution(int[] A) {
        boolean[] num = new boolean[1000001];
        for(int i : A){
            if(i<=0) continue;
            num[i] = true;
        }

        for(int i=1;i<=1000000;i++){
            if(num[i]==false) return i;
        }
        return 1;
    }
}

