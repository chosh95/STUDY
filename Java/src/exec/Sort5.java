package exec;

import java.util.Arrays;

public class Sort5 {

    public static void swap(int[] arr, int idx1, int idx2) {
        int tmp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = tmp;
    }

    private static void bubbleSort(int[] arr) {
        int len = arr.length;
        for (int i = len - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr, j, j + 1);
                }
            }
        }

        Arrays.stream(arr).forEach(x -> System.out.print(x + " "));
    }

    private static void selectionSort(int[] arr) {
        int len = arr.length;
        for (int i = 0; i < len; i++) {
            int minIdx = i;
            for (int j = i; j < len; j++) {
                if (arr[minIdx] > arr[j]) {
                    minIdx = j;
                }
            }
            swap(arr, minIdx, i);
        }
        Arrays.stream(arr).forEach(x -> System.out.print(x + " "));
    }

    private static void insertionSort(int[] arr) {
        int len = arr.length;
        for (int i = 1; i < len; i++) {
            int cur = arr[i];
            int idx = i - 1;
            while (idx >= 0 && cur < arr[idx]) {
                arr[idx] = arr[idx - 1];
                idx--;
            }
            arr[idx + 1] = cur;
        }

        Arrays.stream(arr).forEach(x -> System.out.print(x + " "));
    }

    private static int[] quickSort(int[] arr, int lo, int hi) {
        if (lo >= hi) return arr;

        int pivot = arr[(lo + hi) / 2];
        int left = lo, right = hi;
        while (left <= right) {
            while (arr[left] < pivot)
                left++;
            while (arr[right] > pivot)
                right--;
            if (left <= right) {
                swap(arr, left, right);
                left++;
                right--;
            }
        }

        arr = quickSort(arr, lo, right);
        arr = quickSort(arr, left, hi);

        return arr;
    }

    private static int[] mergeSort(int[] merge, int lo, int hi) {
        if (lo >= hi) return merge;

        int mid = (lo + hi) / 2;

        mergeSort(merge, lo, mid);
        mergeSort(merge, mid + 1, hi);
        merge = doMerge(merge, lo, hi, mid);

        return merge;
    }

    private static int[] doMerge(int[] arr, int lo, int hi, int mid) {
        int[] tmp = new int[hi-lo+1];

        int left = lo, right = mid + 1;

        int idx = 0;
        while (left <= mid && right <= hi) {
            if(arr[left] <= arr[right]) {
                tmp[idx++] = arr[left++];
            }
            else{
                tmp[idx++] = arr[right++];
            }
        }
        while(left<=mid)
            tmp[idx++] = arr[left++];
        while(right<=hi)
            tmp[idx++] = arr[right++];

        idx = 0;
        for(int i=lo; i <=hi; i++){
            arr[i] = tmp[idx++];
        }

        return arr;
    }

    public static void main(String[] args) {
        int[] arr = new int[]{9, 3, 2, 6, 8, 1, 5, 7, 4, 10};

        int[] bubble = Arrays.copyOf(arr, arr.length);
        bubbleSort(bubble);
        System.out.println("\n=============");

        int[] selection = Arrays.copyOf(arr, arr.length);
        selectionSort(selection);
        System.out.println("\n=============");

        int[] insertion = Arrays.copyOf(arr, arr.length);
        insertionSort(selection);
        System.out.println("\n=============");

        int[] quick = Arrays.copyOf(arr, arr.length);
        int[] result = quickSort(quick, 0, arr.length - 1);
        Arrays.stream(result).forEach(x -> System.out.print(x + " "));
        System.out.println("\n=============");

        int[] merge = Arrays.copyOf(arr, arr.length);
        int[] mergeResult = mergeSort(merge, 0, arr.length - 1);
        Arrays.stream(mergeResult).forEach(x -> System.out.print(x + " "));
    }

}
