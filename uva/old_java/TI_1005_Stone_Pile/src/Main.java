import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        int[] piece = new int[n];


        for(int i = 0; i < n; i++)
            piece[i] = s.nextInt();

        int min_diff = 360;

        // starts from i-th piece
        for(int i = 0; i < n; i++) {
            int curr_piece = piece[i];

            for(int j = i + 1; curr_piece + piece[j%n] <= 180; j++) {

                    curr_piece += piece[j%n];

            }

            if(Math.abs(360 - 2*curr_piece) < min_diff)
                min_diff = Math.abs(360 - 2*curr_piece);


        }

        System.out.println(min_diff);
    }
}
