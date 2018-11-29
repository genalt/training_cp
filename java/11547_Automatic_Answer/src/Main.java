import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int TC = s.nextInt();

        for(int i = 0; i < TC; i++) {

            int n = s.nextInt();

            String res = new Long((n * 63 + 7492) * 5 - 498).toString();
            if(res.length() > 2)
                System.out.println( res.charAt(res.length() - 2));
            else
                System.out.println(0);

        }
    }
}
