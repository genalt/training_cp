import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int TC;

        while(true) {
            TC = s.nextInt();
            if(TC == 0)
                break;

            int dx = s.nextInt();
            int dy = s.nextInt();

            for(int t = 0; t < TC; t++) {
                int x = s.nextInt() - dx;
                int y = s.nextInt() - dy;

                if(x == 0 || y == 0) {
                    System.out.println("divisa");
                    continue;
                }

                String answer = "";

                if(y > 0)
                    answer += "N";
                else
                    answer += "S";

                if(x > 0)
                    answer += "E";
                else
                    answer += "O";

                System.out.println(answer);

            }
        }
    }
}
