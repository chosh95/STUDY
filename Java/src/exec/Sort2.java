package exec;

import com.sun.org.apache.bcel.internal.generic.ARRAYLENGTH;

import java.util.Arrays;

public class Sort2 {

    static void swap(int[] arr, int a, int b){
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    static void bubbleSort(int[] arr){
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr.length-i - 1;j++){
                if(arr[j] > arr[j+1])
                    swap(arr,j,j+1);
            }
        }
    }

    public static void selectionSort(int[] arr){
        for(int i=0;i<arr.length;i++){
            int minIdx = i;
            for(int j=i+1;j<arr.length;j++){
                if(arr[minIdx] > arr[j]){
                    minIdx = j;
                }
            }
            swap(arr,i,minIdx);
        }
    }

    public static void insertionSort(int[] arr){
        for(int i=1;i<arr.length;i++){
            int cur = arr[i];
            int idx = i-1;
            while(idx>=0 && arr[idx]>cur)
                arr[idx+1] = arr[idx--];
            arr[idx+1] = cur;
        }
    }

    public static void quickSort(int[] arr, int lo, int hi){
        if(lo >= hi) return;

        int mid = (lo+hi)/2;
        int left = lo, right = hi;
        int pivot = arr[mid];

        while(left<=right){
            while(arr[left] < pivot) left++;
            while(arr[right] > pivot) right--;
            if(left<=right){
                swap(arr,left,right);
                left++;
                right--;
            }
        }

        quickSort(arr,lo,right);
        quickSort(arr,left,hi);
    }

    public static void merge(int[] arr, int lo, int hi,int mid){
        int[] tmp = new int[hi-lo+1];
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

        for(int idx2 =0, i = lo; i<=hi; i++, idx2++)
                arr[i] = tmp[idx2];
    }

    public static void mergeSort(int[] arr,int lo,int hi){
        if(lo>=hi) return;
        int mid = (lo+hi)/2;
        mergeSort(arr,lo,mid);
        mergeSort(arr,mid+1,hi);
        merge(arr,lo,hi,mid);
    }

    public static void main(String[] args) {
        int[] p = new int[]{5,13,2,3,594,10,200,4,5959,123,1,23,53};

        int[] bubble = Arrays.copyOf(p,p.length);
         bubbleSort(bubble);
        System.out.println(Arrays.toString(bubble));

        int[] selection = Arrays.copyOf(p,p.length);
        selectionSort(selection);
        System.out.println(Arrays.toString(selection));

        int[] insertion = Arrays.copyOf(p,p.length);
        insertionSort(insertion);
        System.out.println(Arrays.toString(insertion));

        int[] quick = Arrays.copyOf(p,p.length);
        quickSort(quick,0,quick.length-1);
        System.out.println(Arrays.toString(quick));

        int[] merge = Arrays.copyOf(p,p.length);
        mergeSort(merge,0,p.length-1);
        System.out.println(Arrays.toString(merge));
    }
}
