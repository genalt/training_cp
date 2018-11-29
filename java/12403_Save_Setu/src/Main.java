import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {



        Scanner s = new Scanner(System.in);
        int TC = s.nextInt();
        s.nextLine();
        int sum = 0;
        for(int i = 0; i < TC; i++){
            String op = s.nextLine();

            if(op.equals("report"))
                System.out.println(sum);
            else {
                int add = Integer.parseInt(op.substring(7));
                sum += add;
            }

        }
    }
}
