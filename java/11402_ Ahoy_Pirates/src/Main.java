import java.util.Scanner;
import java.io.*;

public class Main {
    static int[] st;   // Segment Tree
    static int[] lazy;
    static char[] a;

    static void build(int stIndex, int segLeft, int segRight) {
        if(segLeft == segRight) {
            if(a[segLeft] == '1') {
                st[stIndex] = 1;
            }
            return;
        }
        int segMiddle = segLeft + (segRight - segLeft) / 2;
        build(stIndex*2 + 1, segLeft, segMiddle);
        build(stIndex*2 + 2, segMiddle + 1, segRight);

        st[stIndex] = st[stIndex*2 + 1] + st[stIndex*2 + 2];
    }

    static void push(int stIndex, int segLeft, int segRight) {
        if(lazy[stIndex] != 0) {
            if(lazy[stIndex] == 1) {
                st[stIndex] = 0;
            }
            else if(lazy[stIndex] == 2) {
                st[stIndex] = segRight - segLeft + 1;
            }
            else {
                if(segLeft != segRight){
                    int segMiddle = segLeft + (segRight - segLeft) / 2;
                    push(stIndex * 2 + 1, segLeft, segMiddle);
                    push(stIndex * 2 + 2, segMiddle + 1, segRight);
                }

                st[stIndex] = (segRight - segLeft + 1) - st[stIndex];
            }

            if(segLeft != segRight){
                lazy[stIndex*2 + 1] = lazy[stIndex];
                lazy[stIndex*2 + 2] = lazy[stIndex];
            }
            lazy[stIndex] = 0;
        }
    }

    static int rzq(int stIndex, int segLeft, int segRight, int reqLeft, int reqRight) {
        push(stIndex, segLeft, segRight);

        if(reqLeft > segRight || reqRight < segLeft)
            return 0;

        if(segLeft >= reqLeft && segRight <= reqRight)
            return st[stIndex];

        int segMiddle = segLeft + (segRight - segLeft)/2;

        return rzq(stIndex*2 + 1, segLeft, segMiddle, reqLeft, reqRight) +
                rzq(stIndex*2 + 2, segMiddle + 1, segRight, reqLeft, reqRight);

    }

    static void set(int stIndex, int segLeft, int segRight, int left, int right, int val) {

        push(stIndex, segLeft, segRight);

        if (left > segRight || right < segLeft)
            return;

        if (segLeft >= left && segRight <= right) {
            lazy[stIndex] = val;
            push(stIndex, segLeft, segRight);
            return;
        }

        int segMiddle = segLeft + (segRight - segLeft) / 2;

        set(stIndex * 2 + 1, segLeft, segMiddle, left, right, val);
        set(stIndex * 2 + 2, segMiddle + 1, segRight, left, right, val);

        st[stIndex] = st[stIndex * 2 + 1] + st[stIndex * 2 + 2];
    }


    public static void main(String[] args) {

        Scanner s = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int TC = s.nextInt();

        int ncase = 1; // number of test case
        int question;  // number of question 'S' in a test case
        for(int t=0; t<TC; t++) {

            System.out.printf("Case %d:\n", ncase);
            ncase++;

            question = 1;
            // build land
            int num_patterns = s.nextInt();

            StringBuilder land = new StringBuilder();

            for(int p=0; p < num_patterns; p++) {
                int repeats = s.nextInt();
                String pattern = s.next();

                for(int r=0; r < repeats; r++) {
                    land.append(pattern);
                }
            }

            a = land.toString().toCharArray();

            st = new int[a.length * 4];
            lazy = new int[a.length * 4];
            build(0, 0, a.length -1);

            // process requests
            int num_req = s.nextInt();

            for(int r=0; r < num_req; r++) {

                String R = s.next();
                int left = s.nextInt();
                int right = s.nextInt();

                // set to Buccaneer, 1
                if(R.compareTo("F") == 0)
                    set(0, 0, a.length - 1, left, right, 2 );

                // set to Barbary, 0
                if(R.compareTo("E") == 0)
                    set(0, 0, a.length - 1, left, right, 1);

                // inverse
                if(R.compareTo("I") == 0)
                    set(0, 0, a.length - 1, left, right, 3);

                if(R.compareTo("S") == 0) {
                    System.out.printf("Q%d: %d\n", question, rzq(0, 0, a.length - 1, left, right));
                    question++;
                }
            }
        }
    }
}
