public class SparseTable {
    int st[][];
    int log2[];

    SparseTable(int[] origArray) {

        int origLength = origArray.length;

        log2 = new int[origLength + 1];

        for(int i = 2; i <= origLength; i++)
            log2[i] = log2[i / 2] + 1;

        st = new int[log2[origLength] + 1][origLength];

        for(int power = 0; power < log2.length; power++) {

            int length = 1 << power;  // 2^power

            for (int from = 0; from + length <= origArray.length; from++)
                if (power == 0)
                    st[power][from] = origArray[from];
                else
                    st[power][from] = Math.min(st[power - 1][from], st[power - 1][from + length/2]);
        }
    }

    int rmq(int leftIndex, int rightIndex) {
        int level = log2[rightIndex - leftIndex + 1];  // size of segment
        return Math.min(st[level][leftIndex], st[level][rightIndex - (1 << level) + 1]);
    }

    // test
    public static void main(String[] args) {
        int[] a = {1, 29, 0, -3, 4, 5, 7, 34, 2, 88, 15};
        SparseTable my_st = new SparseTable(a);
        System.out.println(my_st.rmq(5, 7));
    }
}
