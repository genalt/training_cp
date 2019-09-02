import java.io.*;
import java.util.Scanner;

class Main {
    static int[] segmentTree;
    static int[] originArray;

    static void build(int stIndex, int origLeft, int origRight){

        if(origLeft == origRight) { // in leaf
            segmentTree[stIndex] = originArray[origLeft];
            return;
        }
        int origMiddle = origLeft + (origRight - origLeft) / 2;

        build(2*stIndex + 1, origLeft, origMiddle);          // build left child
        build(2*stIndex + 2, origMiddle +1, origRight);  // build origRight child

        segmentTree[stIndex] = segmentTree[2*stIndex + 1] + segmentTree[2*stIndex + 2];

    }

    static int sum(int i, int j) {
        return sum(0, 0, originArray.length-1, i, j);
    }

    static int sum(int v, int vl, int vr, int i, int j) {

        if(i > vr || j < vl)
            return 0;

        if(vl >= i && vr <= j)
            return segmentTree[v];

        int vm = vl + (vr - vl) / 2;

        return sum(2*v + 1, vl, vm, i, j) + sum(2*v + 2, vm + 1, vr, i, j);

    }

    static void set(int i, int v) {
        set(0, 0, originArray.length - 1, i, v);
    }

    static void set(int v, int vl, int vr, int i, int val) {

        if(i < vl || i > vr)
            return;

        if(vl == i && vr == i) {
            segmentTree[v] = val;
            return;
        }

        int vm = vl + (vr - vl) / 2;
        set(2*v + 1, vl, vm, i, val);
        set(2*v + 2, vm +1, vr, i, val);

        segmentTree[v] = segmentTree[v*2 + 1] + segmentTree[v*2 + 2];

    }



    public static void main(String[] args) {
        Scanner s = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter p = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int n;
        int ncase = 1;

        while(true) {
            n = s.nextInt();
            if(n == 0)
                break;

            originArray = new int[n];
            segmentTree = new int[n * 4];
            for(int i=0; i<n; i++)
                originArray[i] = s.nextInt();
            build(0, 0, n -1);


            if(ncase != 1)
                p.println();
            p.printf("Case %d:\n", ncase);

            p.flush();

            //process requests
            String req = "";
            while(true) {

                req = s.next();
                if(req.compareTo("END") == 0)
                    break;
                int n1 = s.nextInt();
                int n2 = s.nextInt();
                //p.println("You req is: " + req);
                p.flush();

                if(req.equals("M")) { // measure
                    p.println(sum(n1 - 1, n2 - 1));
                    p.flush();
                }
                if(req.equals("S")) {
                    set(n1 - 1, n2);
                }

            }

            ncase++;
        }
        p.close();
        s.close();
    }
}




