import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int TC = s.nextInt();

        for(int i = 0; i < TC; i++) {
            int[] a = new int[3];
            a[0] = s.nextInt();
            a[1] = s.nextInt();
            a[2] = s.nextInt();
            Arrays.sort(a);

            System.out.printf("Case %d: %d\n", i+1, a[1]);

        }
    }
}
