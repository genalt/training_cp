import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {



        Scanner s = new Scanner(System.in);
        int num = 1;
        while(true) {
            int TC = s.nextInt();

            if(TC == 0)
                break;
            int z = 0;
            int nz = 0;
            for (int i = 0; i < TC; i++) {
                if(s.nextInt() > 0)
                    nz++;
                else
                    z++;
            }
            System.out.printf("Case %d: %d\n", num, nz - z);
            num++;

        }
    }
}
