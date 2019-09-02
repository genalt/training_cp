import java.util.Arrays;

public class binarySearch {
    static int search(int[] a, int key) {

        int l = 0;
        int r = a.length - 1;


        while(l <= r) {
            int m =  (l + r) / 2;
            if(a[m] == key)
                return m;
            else if (a[m] < key)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] a  = {7, 9, 10};

        Arrays.sort(a);

        System.out.println(search(a, 9));

    }
}
