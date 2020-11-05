package exec;

public class BinarySearch {

    public static void main(String[] args) {
        int[] p = new int[]{1,5,7,9,16,21,53,100};
        int lo = 0, hi = p.length - 1;

        int key = 21;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(p[mid]<key)
                lo = mid+1;
            else if(p[mid] > key)
                hi = mid -1;
            else {
                System.out.println(mid);
                break;
            }
        }
    }
}
