package exec;

import java.util.Arrays;

public class Sort3 {

    public static void swap(int[] arr, int a, int b){
        int tmp = arr[a];
        arr[a] =arr [b];
        arr[b] = tmp;
    }

    public static void bubbleSort(int[] arr){
        for(int i=0;i<arr.length;i++)
            for(int j=0;j<arr.length-i-1;j++)
                if(arr[j]>arr[j+1])
                    swap(arr,j,j+1);
    }

    private static void selectSort(int[] arr) {
        for(int i=0;i<arr.length;i++){
            int minIdx = i;
            for(int j=i+1;j<arr.length;j++){
                if(arr[minIdx]>arr[j])
                    minIdx = j;
            }
            swap(arr,minIdx,i);
        }
    }

    private static void insertSort(int[] arr) {
        for(int i=1;i<arr.length;i++){
            int cur = arr[i];
            int idx = i-1;
            while(idx>=0 && arr[idx]>cur)
                arr[idx+1] = arr[idx--];
            arr[idx+1] = cur;
        }
    }

    private static void quickSort(int[] arr, int lo, int hi) {
        if(lo>=hi) return;
        int left = lo, right = hi;
        int pivot = arr[(lo+hi)/2];

        while(left<=right){
            while(arr[left]<pivot) left++;
            while(arr[right]>pivot) right--;
            if(left<=right){
                swap(arr,left,right);
                left++;
                right--;
            }
        }

        quickSort(arr,lo,right);
        quickSort(arr,left,hi);
    }

    public static void mergeSort(int[] arr, int lo, int hi){
        if(lo>=hi) return;
        int mid = (lo+hi)/2;
        mergeSort(arr,lo,mid);
        mergeSort(arr,mid+1,hi);
        doMerge(arr,lo,hi);
    }

    public static void doMerge(int[] arr, int lo, int hi){
        int[] tmp = new int[hi-lo+1];
        int mid = (lo+hi)/2;
        int left = lo, right = mid+1;

        int idx = 0;
        while(left<=mid && right<=hi){
            if(arr[left]<arr[right])
                tmp[idx++] = arr[left++];
            else
                tmp[idx++] = arr[right++];
        }

        while(left<=mid)
            tmp[idx++] = arr[left++];
        while(right<=hi)
            tmp[idx++] = arr[right++];

        idx = 0;
        for(int i=lo;i<=hi;i++)
            arr[i] = tmp[idx++];
    }

    public static void main(String[] args) {
        int[] p = new int[]{3,1,5,2,4,7,8,6,5,9,11};

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
