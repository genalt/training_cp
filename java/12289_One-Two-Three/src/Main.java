import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {



        Scanner s = new Scanner(System.in);
        int TC = s.nextInt();
        for(int i = 0; i < TC; i++){
            String num = s.next();

            if (num.length() == 5)
                System.out.println("3");

            else if (num.startsWith("t")){
                if (num.endsWith("ne"))
                    System.out.println("1");
                else
                    System.out.println("2");
            }
            else if (num.startsWith("o")) {
                if (num.endsWith("wo"))
                    System.out.println("2");
                else
                    System.out.println("1");
            }
            else {
                if (num.endsWith("wo"))
                    System.out.println("2");
                else
                    System.out.println("1");
            }

        }
    }
}
