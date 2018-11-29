
public class Kadanes {
    static int getMaxProd(int[] a) {
        int max = a[0];
        int cur_min = a[0];
        int cur_max = a[0];

        int tmp;

        for(int i=1; i< a.length; i++) {
            tmp = cur_max;

            cur_max = Math.max(Math.max(a[i], cur_max * a[i]), cur_min * a[i]);
            cur_min = Math.min(Math.min(a[i], tmp * a[i]), cur_min * a[i]);

            if(cur_max > max)
                max = cur_max;
        }
        return max;
    }

    static int getMaxSum(int[] a) {
        int max_sum = a[0];
        int cur_sum = a[0];

        for (int i = 1; i < a.length; i++) {
            cur_sum = Math.max(a[i], cur_sum + a[i]);

            if (cur_sum > max_sum)
                max_sum = cur_sum;
        }
        return max_sum;
    }


    public static void main(String[] args) {

        int[] test = {-1, 0, -2, 1, 4, -2, 1, -6};
        System.out.println(getMaxSum(test));
        System.out.println(getMaxProd(test));


    }
}
