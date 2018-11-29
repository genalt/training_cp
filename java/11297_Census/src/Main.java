import java.util.Scanner;

class Node {
    public int min;
    public int max;
    Node() {
        min = Integer.MAX_VALUE;
        max = Integer.MIN_VALUE;
    }
}


class SegmentTree {

    Node[] segmentTree;
    int N;

    SegmentTree(int[] a) {

        N = a.length;
        segmentTree = new Node[4 * N];
        for(int i=0; i< segmentTree.length; i++)
            segmentTree[i] = new Node();

        build(0, 0, a.length - 1, a);

    }

    private void build(int idx, int segLeft, int segRight, int[] a) {

        if (segLeft == segRight) {  // in a leaf
            segmentTree[idx].min = a[segLeft];
            segmentTree[idx].max = a[segLeft];
            return;
        }

        int rangeMiddle = segLeft + (segRight - segLeft) / 2;

        build(2 * idx + 1, segLeft, rangeMiddle, a);
        build(2 * idx + 2, rangeMiddle + 1, segRight, a);

        segmentTree[idx].min = Math.min(segmentTree[2 * idx + 1].min, segmentTree[2 * idx + 2].min);
        segmentTree[idx].max = Math.max(segmentTree[2 * idx + 1].max, segmentTree[2 * idx + 2].max);

    }


    private int getMin(int stIndex, int segmentLeft, int segmentRight, int reqLeft, int reqRight) {

        if (reqLeft > segmentRight || reqRight < segmentLeft)
            return Integer.MAX_VALUE;

        if (segmentLeft >= reqLeft && segmentRight <= reqRight)
            return segmentTree[stIndex].min;

        int segmentMiddle = segmentLeft + (segmentRight - segmentLeft) / 2;

        return Math.min(getMin(2 * stIndex + 1, segmentLeft, segmentMiddle, reqLeft, reqRight),
                getMin(2 * stIndex + 2, segmentMiddle + 1, segmentRight, reqLeft, reqRight));
    }

    private int getMax(int stIndex, int segLeft, int segRight, int reqLeft, int reqRight) {

        if (reqLeft > segRight || reqRight < segLeft)
            return Integer.MIN_VALUE;

        if (segLeft >= reqLeft && segRight <= reqRight)
            return segmentTree[stIndex].max;

        int segMiddle = segLeft + (segRight - segLeft) / 2;

        return Math.max(getMax(2 * stIndex + 1, segLeft, segMiddle, reqLeft, reqRight),
                getMax(2 * stIndex + 2, segMiddle + 1, segRight, reqLeft, reqRight));
    }

    private void set(int stIndex, int segmentLeft, int segmentRight, int pos, int val) {

        if (pos > segmentRight || pos < segmentLeft)
            return;

        if (segmentLeft == pos && segmentRight == pos) {
            segmentTree[stIndex].min = val;
            segmentTree[stIndex].max = val;
            return;
        }

        int segmentMiddle = segmentLeft + (segmentRight - segmentLeft) / 2;

        set(2 * stIndex + 1, segmentLeft, segmentMiddle, pos, val);
        set(2 * stIndex + 2, segmentMiddle + 1, segmentRight, pos, val);

        segmentTree[stIndex].min = Math.min(segmentTree[2 * stIndex + 1].min, segmentTree[2 * stIndex + 2].min);
        segmentTree[stIndex].max = Math.max(segmentTree[2 * stIndex + 1].max, segmentTree[2 * stIndex + 2].max);
    }


    int getMin(int reqLeft, int reqRight) {
        return getMin(0, 0, N -1, reqLeft, reqRight);
    }
    int getMax(int reqLeft, int reqRight) {
        return getMax(0, 0, N -1, reqLeft, reqRight);
    }


    void set(int pos, int val) {
        set(0, 0, N - 1, pos, val);
    }
}



public class Main {
    //tests
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int N = s.nextInt();
        SegmentTree[] st = new SegmentTree[N];
        int[] a = new int[N];

        // build N Segmet Trees
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                a[j] = s.nextInt();
            st[i] = new SegmentTree(a);
        }

        int Q = s.nextInt();

        for(int i=0; i < Q; i++) {
            String q = s.next();

            //make query
            if(q.compareTo("q") == 0) {
                int top = s.nextInt() - 1;
                int left = s.nextInt() - 1;

                int bottom = s.nextInt() - 1;
                int right = s.nextInt() - 1;

                int min = Integer.MAX_VALUE;
                int max = Integer.MIN_VALUE;

                for(int j = top; j<= bottom; j++) {
                    int cur_min = st[j].getMin(left, right);
                    int cur_max = st[j].getMax(left, right);

                    min = Math.min(min, cur_min);
                    max = Math.max(max, cur_max);
                }

                System.out.println(max + " " + min);
            }
            else {
                int x = s.nextInt() - 1;
                int y = s.nextInt() - 1;
                int v = s.nextInt();
                st[x].set(y, v);
            }
            //make changes

        }
    }
}
