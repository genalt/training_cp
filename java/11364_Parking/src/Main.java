import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int TC = s.nextInt();

        for(int i = 0; i < TC; i++) {
            int dist = 0;
            int n = s.nextInt();
            int[] arr = new int[n];
            for(int j = 0; j <n; j++)
                arr[j] = s.nextInt();


            Arrays.sort(arr);

            for(int j = 0; j < n; j++) {

                if(j == n - 1)
                    dist += arr[j] - arr[0];
                else
                    dist += arr[j+1] - arr[j];

            }

            System.out.println(dist);



        }
    }
}
