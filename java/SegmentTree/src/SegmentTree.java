public class SegmentTree {

    int[] segmentTreeMin;
    int origSize;

    SegmentTree(int[] origArray) {

        origSize = origArray.length;
        segmentTreeMin = new int[4 * origSize];
        build(0, 0, origArray.length - 1, origArray);

    }

    private void build(int stIndex, int segmentLeft, int segmentRight, int[] origArray) {

        if (segmentLeft == segmentRight) {  // in a leaf
            segmentTreeMin[stIndex] = origArray[segmentLeft];
            return;
        }

        int rangeMiddle = (segmentLeft + segmentRight) / 2;

        build(2 * stIndex + 1, segmentLeft, rangeMiddle, origArray);
        build(2 * stIndex + 2, rangeMiddle + 1, segmentRight, origArray);

        segmentTreeMin[stIndex] = Math.min(segmentTreeMin[2 * stIndex + 1], segmentTreeMin[2 * stIndex + 2]);

    }


    private int rmq(int stIndex, int segmentLeft, int segmentRight, int reqLeft, int reqRight) {

        if (reqLeft > segmentRight || reqRight < segmentLeft)
            return Integer.MAX_VALUE;

        if (segmentLeft >= reqLeft && segmentRight <= reqRight)
            return segmentTreeMin[stIndex];

        int segmentMiddle = (segmentLeft + segmentRight) / 2;

        return Math.min(rmq(2 * stIndex + 1, segmentLeft, segmentMiddle, reqLeft, reqRight),
                        rmq(2 * stIndex + 2, segmentMiddle + 1, segmentRight, reqLeft, reqRight));
    }

    private void set(int stIndex, int segmentLeft, int segmentRight, int pos, int val) {

        if (pos > segmentRight || pos < segmentLeft)
            return;

        if (segmentLeft == pos && segmentRight == pos) {
            segmentTreeMin[stIndex] = val;
            return;
        }

        int segmentMiddle = (segmentLeft + segmentRight) / 2;

        set(2 * stIndex + 1, segmentLeft, segmentMiddle, pos, val);
        set(2 * stIndex + 2, segmentMiddle + 1, segmentRight, pos, val);

        segmentTreeMin[stIndex] = Math.min(segmentTreeMin[2 * stIndex + 1], segmentTreeMin[2 * stIndex + 2]);
    }


    int rmq(int reqLeft, int reqRight) {
        return rmq(0, 0, origSize -1, reqLeft, reqRight);
    }


    void set(int pos, int val) {
        set(0, 0, origSize - 1, pos, val);
    }




    //tests
    public static void main(String[] args) {
        int[] a = {1, -2, 0, 13, 4, 26, -3};
        SegmentTree st = new SegmentTree(a);
        //System.out.println(st.rsq(0, 0, a.length, 1, 4));
        System.out.println(st.rmq(0, a.length - 1));


    }
}
