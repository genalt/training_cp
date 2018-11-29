import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int TC = s.nextInt();

        for(int i = 0; i < TC; i++) {
            int m = s.nextInt();
            int n = s.nextInt();


            System.out.println( (n/3) * (m/3));


        }
    }
}
