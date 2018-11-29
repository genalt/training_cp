import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader s = new BufferedReader(new InputStreamReader(System.in));
        //Scanner s = new Scanner(System.in);
        int T = Integer.parseInt(s.readLine());
        while (T-- > 0) {
            int N = Integer.parseInt(s.readLine());
            int[] arr = new int[N];
            int min = 1001;

            for (int i = 0; i < N; i++) {
                int nn = s.readLine().split(" ").length;
                arr[i] = nn;
                if (nn < min)
                    min = nn;
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < arr.length; i++) {
                if (arr[i] == min) {
                    sb.append(i+1).append(" ");
                }

            }
            System.out.println(sb.toString().trim());

            if (T != 0) {
                s.readLine(); // read empty line
            }
        }
    }

}
