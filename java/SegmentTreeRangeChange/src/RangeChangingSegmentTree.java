public class RangeChangingSegmentTree {

    int[] segmentTreeSum;
    int[] lazy;
    int origSize;

    RangeChangingSegmentTree(int[] origArray) {

        origSize = origArray.length;
        segmentTreeSum = new int[4 * origSize];
        lazy = new int[4 * origSize];
        build(0, 0, origArray.length - 1, origArray);

    }

    private void build(int stIndex, int segmentLeft, int segmentRight, int[] origArray) {

        if (segmentLeft == segmentRight) {  // in a leaf
            segmentTreeSum[stIndex] = origArray[segmentLeft];
            return;
        }

        int rangeMiddle = segmentLeft + (segmentRight - segmentLeft) / 2;

        build(2 * stIndex + 1, segmentLeft, rangeMiddle, origArray);
        build(2 * stIndex + 2, rangeMiddle + 1, segmentRight, origArray);

        segmentTreeSum[stIndex] = segmentTreeSum[2 * stIndex + 1] + segmentTreeSum[2 * stIndex + 2];

    }


    private int rsq(int stIndex, int segmentLeft, int segmentRight, int reqLeft, int reqRight) {
        lazyPush(stIndex, segmentLeft, segmentRight);

        if (reqLeft > segmentRight || reqRight < segmentLeft)
            return 0;

        if (segmentLeft >= reqLeft && segmentRight <= reqRight)
            return segmentTreeSum[stIndex];

        int segmentMiddle = segmentLeft + (segmentRight - segmentLeft) / 2;

        return rsq(2 * stIndex + 1, segmentLeft, segmentMiddle, reqLeft, reqRight) +
                rsq(2 * stIndex + 2, segmentMiddle + 1, segmentRight, reqLeft, reqRight);
    }


    private void setRange(int stIndex, int segmentLeft, int segmentRight, int setLeft, int setRight, int val) {
        lazyPush(stIndex, segmentLeft, segmentRight);

        if (setLeft > segmentRight || setRight < segmentLeft)
            return;

        if (segmentLeft >= setLeft && segmentRight <= setRight) {
            lazy[stIndex] += val;
            lazyPush(stIndex, segmentLeft, segmentRight);
            return;
        }

        int segmentMiddle = segmentLeft + (segmentRight - segmentLeft) / 2;

        setRange(2 * stIndex + 1, segmentLeft, segmentMiddle, setLeft, setRight, val);
        setRange(2 * stIndex + 2, segmentMiddle + 1, segmentRight, setLeft, setRight, val);

        segmentTreeSum[stIndex] = segmentTreeSum[stIndex*2 + 1] + segmentTreeSum[stIndex*2 + 2];
    }

    private void lazyPush(int stIndex, int segmentLeft, int segmentRight) {
        int val = lazy[stIndex];
        if(val != 0) { // need to push
            segmentTreeSum[stIndex] = lazy[stIndex] * (segmentRight - segmentLeft + 1);
            lazy[stIndex * 2 + 1] = val;
            lazy[stIndex * 2 + 2] = val;
            lazy[stIndex] = 0;
        }
    }


    int rsq(int reqLeft, int reqRight) {
        return rsq(0, 0, origSize -1, reqLeft, reqRight);
    }


    void setRange(int posLeft, int posRight, int val) {
        setRange(0, 0, origSize - 1, posLeft, posRight, val);
    }


    //tests
    public static void main(String[] args) {
        int[] a = {1, 2, 0, -3, 4, 26, 0};
        RangeChangingSegmentTree st = new RangeChangingSegmentTree(a);
        System.out.println(st.rsq(0, 2));
        st.setRange(0, 2, 10);
        System.out.println(st.rsq(0, 3));
    }
}
