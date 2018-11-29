import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {



        Scanner s = new Scanner(System.in);
        int TC = s.nextInt();
        for(int i = 0; i < TC; i++){
           int l = s.nextInt();
           int w = s.nextInt();
           int h = s.nextInt();

           if(l<=20 && w <= 20 && h <= 20)
               System.out.printf("Case %d: good\n", i +1);
           else
               System.out.printf("Case %d: bad\n", i +1);

        }
    }
}
