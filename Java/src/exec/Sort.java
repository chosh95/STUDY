package exec;

import java.util.Arrays;

public class Sort {
    public static void doSwap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    public static void bubbleSort(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            for (int j = 0; j < arr.length - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    doSwap(arr, j, j + 1);

        Arrays.stream(arr).forEach((x) -> System.out.print(x + " "));
    }

    public static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int minIdx = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[minIdx] > arr[j])
                    minIdx = j;
            }
            doSwap(arr, i, minIdx);
        }

        Arrays.stream(arr).forEach((x) -> System.out.print(x + " "));
    }

    public static void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int cur = arr[i];
            int idx = i - 1;
            while (idx >= 0 && arr[idx] > cur) {
                arr[idx + 1] = arr[idx];
                idx--;
            }
            arr[idx + 1] = cur;
        }

        Arrays.stream(arr).forEach((x) -> System.out.print(x + " "));
    }

    public static int[] quickSort(int[] arr, int lo, int hi) {
        if (lo >= hi) return arr;

        int pivot = arr[(lo + hi) / 2];
        int left = lo, right = hi;

        while (left <= right) {
            while (arr[left] < pivot)
                left++;
            while (pivot < arr[right])
                right--;
            if (left <= right) {
                doSwap(arr, left, right);
                left++;
                right--;
            }
        }

        arr = quickSort(arr, lo, right);
        arr = quickSort(arr, left, hi);

        return arr;
    }

    public static int[] doMerge(int[] arr, int lo, int hi, int mid) {
        int[] tmp = new int[arr.length];
        int left = lo, right = mid + 1;
        int idx = left;
        while (left <= mid && right <= hi) {
            if (arr[left] < arr[right])
                tmp[idx++] = arr[left++];
            else
                tmp[idx++] = arr[right++];
        }
        while (left <= mid)
            tmp[idx++] = arr[left++];
        while (right <= hi)
            tmp[idx++] = arr[right++];

        for (int i = lo; i <= hi; i++)
            arr[i] = tmp[i];

        return arr;
    }

    public static int[] mergeSort(int[] arr, int lo, int hi) {
        if (lo >= hi) return arr;
        int mid = (lo + hi) / 2;
        arr = mergeSort(arr, lo, mid);
        arr = mergeSort(arr, mid + 1, hi);
        arr = doMerge(arr, lo, hi, mid);
        return arr;
    }


    public static void main(String[] args) {
        int[] p = new int[]{9, 3, 2, 6, 8, 1, 5, 7, 4, 10};

        int[] bubble = Arrays.copyOf(p, p.length);
        bubbleSort(bubble);
        System.out.println();

        int[] selection = Arrays.copyOf(p, p.length);
        selectionSort(selection);
        System.out.println();

        int[] insertion = Arrays.copyOf(p, p.length);
        insertionSort(insertion);
        System.out.println();

        int[] quick = Arrays.copyOf(p, p.length);
        quick = quickSort(quick, 0, quick.length - 1);
        Arrays.stream(quick).forEach((x) -> System.out.print(x + " "));
        System.out.println();

        int[] merge = Arrays.copyOf(p, p.length);
        merge = mergeSort(merge, 0, merge.length - 1);
        Arrays.stream(merge).forEach((x) -> System.out.print(x + " "));
        System.out.println();
    }
}
