
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        while(s.hasNext()) {
            int res = 1080;
            int start = s.nextInt();
            int first = s.nextInt();
            int second = s.nextInt();
            int third = s.nextInt();

            if (start == 0 && first == 0 && second == 0 && third == 0)
                break;


           //System.out.println(res);

            if (start > first) {

                res += 9 * (start - first);
                //System.out.println(9 * (start - first));
            }
            else {
                res += 9 * (start + 40 - first);
                //System.out.println(9 * (start + 40 - first));

            }

            //system.out.println()


            if (second > first) {
                res += 9 * (second - first);
            }
            else {
                res += 9 * (40 - first + second);
            }

            if (second > third) {
                res += 9 * (second - third);
            }
            else {
                res += 9 * (second + 40 - third);
            }



            System.out.println(res);


        }
    }
}
