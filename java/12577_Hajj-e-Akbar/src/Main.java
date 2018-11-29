import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {



        Scanner s = new Scanner(System.in);
        int t = 1;

        while(true) {
            String word = s.next();
            if(word.equals("*")) {
                break;
            }

            if(word.equals("Hajj"))
                System.out.printf("Case %d: Hajj-e-Akbar\n", t);
            else
                System.out.printf("Case %d: Hajj-e-Asghar\n", t);

            t++;

        }
    }
}
