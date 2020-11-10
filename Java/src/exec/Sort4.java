package exec;

import java.util.Arrays;

public class Sort4 {

    private static void swap(int[] arr, int j, int i) {
        int tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
    }

    private static void bubbleSort(int[] arr) {
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr.length-i-1;j++){
                if(arr[j]>arr[j+1])
                    swap(arr,j,j+1);
            }
        }
    }

    private static void selectSort(int[] arr) {
        for(int i=0;i<arr.length;i++){
            int minIdx = i;
            for(int j=i;j<arr.length;j++){
                if(arr[minIdx] > arr[j])
                    minIdx = j;
            }
            swap(arr,i,minIdx);
        }
    }

    private static void insertSort(int[] arr) {
        for(int i=1;i<arr.length;i++){
            int cur = arr[i];
            int idx = i-1;
            while(idx>=0 && arr[idx]>cur){
                arr[idx+1] = arr[idx--];
            }
            arr[idx+1] = cur;
        }
    }

    private static void quickSort(int[] arr, int lo, int hi) {
        if(lo>=hi) return;
        int pivot = arr[(lo+hi)/2];
        int left = lo , right = hi;
        while(left<=right){
            while(arr[left]<pivot)left++;
            while(arr[right]>pivot)right--;
            if(left<=right){
                swap(arr,left,right);
                left++;
                right--;
            }
        }

        quickSort(arr,lo,right);
        quickSort(arr,left,hi);
    }

    private static void mergeSort(int[] arr, int lo, int hi) {
        if(lo>=hi) return;
        int mid = (lo+hi)/2;

        mergeSort(arr,lo,mid);
        mergeSort(arr,mid+1,hi);
        merge(arr,lo,hi);

    }

    private static void merge(int[] arr, int lo, int hi) {
        if(lo>=hi) return;
        int[] tmp = new int[hi-lo+1];
        int mid = (lo+hi)/2;
        int left = lo, right = mid+1;
        int idx = 0;

        while(left<=mid && right<=hi){
            if(arr[left] < arr[right])
                tmp[idx++] = arr[left++];
            else
                tmp[idx++] = arr[right++];
        }
        while(left<=mid)
            tmp[idx++] = arr[left++];
        while(right<=hi)
            tmp[idx++] = arr[right++];

        idx = 0;
        for(int i=lo;i<=hi;i++){
            arr[i] = tmp[idx++];
        }
    }

    public static void main(String[] args) {
        int[] p = new int[]{10,4,2,395,6,1,3,5,12,1414};

        int[] bubble = Arrays.copyOf(p,p.length);
        bubbleSort(bubble);
        System.out.println(Arrays.toString(bubble));

        int[] select = Arrays.copyOf(p,p.length);
        selectSort(select);
        System.out.println(Arrays.toString(select));

        int[] insert = Arrays.copyOf(p,p.length);
        insertSort(insert);
        System.out.println(Arrays.toString(insert));

        int[] quick = Arrays.copyOf(p,p.length);
        quickSort(quick,0,quick.length-1);
        System.out.println(Arrays.toString(quick));

        int[] merge = Arrays.copyOf(p,p.length);
        mergeSort(merge,0,merge.length-1);
        System.out.println(Arrays.toString(merge));
    }
}
