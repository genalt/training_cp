import java.util.Scanner;
import java.util.Collections;
import java.util.Arrays;
import java.io.*;

public class snipetIO {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();
        System.out.format("Echo: %d\n", N);

        Scanner sb = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        double D = sb.nextDouble();
        PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        System.out.println(D);
        System.out.printf("orig: %f\n", D);
        pr.format("%.15f\n", D);
        pr.format("%.3f\n", D);
        pr.flush();
    }
}

