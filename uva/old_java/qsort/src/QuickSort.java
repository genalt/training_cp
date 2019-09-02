import java.util.Random;

//one possible implementation of quick sort

public class QuickSort {

    public static void main(String[] args) {



        for(int t = 0; t < 1000; t++) {
            int size = (int) (Math.random() * 10000);
            //System.out.println(size);
            int[] a = new int[size];
            Random generator = new Random();
            for (int i = 0; i < size; i++)
                a[i] = generator.nextInt();

            quickSort2(a, 0, a.length - 1);

            //int[] b = {1, 2, 4, 7, -8};
            assert (isSorted(a));
        }

    }

    public static boolean isSorted(int[] a) {
        for(int i = 1; i < a.length; i++)
            if(a[i] < a[i-1])
                return false;
        return true;
    }

    public static void quickSort(int[] a, int start, int end) {
        if(start >= end || start < 0 || end >= a.length)
            return;

        int l, r, m, tmp; // left, right, middle indices
        l = r = start;
        m = start + (end - start)/2;

        // swap pivot and the last element
        tmp = a[m];
        a[m] = a[end];
        a[end] = tmp;

        while(l < end && r < end ) {
            while(a[l] <= a[end] && l < end )
                l++;

            if(r <= l && l != end)
                r = l + 1;

            while(a[r] >= a[end] && r < end)
                r++;

            if(l != end && r != end) {
                // swap two elements
                tmp = a[l];
                a[l] = a[r];
                a[r] = tmp;
            }
        }

        // swap pivot back to its final place
        if(l != end) {
            tmp = a[l];
            a[l] = a[end];
            a[end] = tmp;
        }

        quickSort(a, start, l - 1);
        quickSort(a, l + 1, end);
    }


    public static void quickSort2(int[] a, int start, int end) {
        if(start >= end || start < 0 || end >= a.length)
            return;

        int l, r, tmp, pivot;
        l = start;
        r = end;
        pivot = a[(start + end)/2];

        while(l < r) {
            while(a[l] < pivot && l < r)
                l++;

            while(a[r] > pivot && r > l)
                r--;

            if (l < r) {
                // swap two elements
                tmp = a[l];
                a[l] = a[r];
                a[r] = tmp;
                l++; r--;
            }
        }
        if(a[l] < pivot)
            l++;
        quickSort(a, start, l - 1);
        quickSort(a, l, end);
    }
}