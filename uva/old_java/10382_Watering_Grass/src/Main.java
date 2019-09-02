import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while(s.hasNext()) {

            int n = s.nextInt();
            double l = s.nextInt();
            double w = s.nextInt() / 2.0;
            Map<Double, Double> sprinklers = new TreeMap<>();

            while(n-- > 0) {
                double x = s.nextInt();
                double r = s.nextInt();
                double dx = Math.sqrt(r*r - w*w);

                if(r < w || x - dx > l || x + dx < 0)
                    continue;

                sprinklers.put(x - dx, x + dx);
            }

            double point = 0;
            int taken = 0;
            double rightmost = -1;

            for(Map.Entry<Double, Double> sprinkler: sprinklers.entrySet()) {
                double left = sprinkler.getKey();
                double right = sprinkler.getValue();

                if(left > point) {
                    if(rightmost > point && rightmost > left) {
                        point = rightmost;
                        taken++;
                    } else
                        break;
                }

                if(right > point && right > rightmost) {
                    rightmost = right;
                    if(rightmost >= l) {
                        taken++;
                        break;
                    }
                }
            }

            if(rightmost < l)
                System.out.println(-1);
            else
                System.out.println(taken);
        }
    }
}
