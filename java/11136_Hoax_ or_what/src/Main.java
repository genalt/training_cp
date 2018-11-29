import java.util.Scanner;
import java.util.TreeMap;


public class Main {

    public static void main(String[] args) {
        int days;    // 1..5000
        int bills;   // 0..100000
        long total;
        TreeMap<Integer, Integer> urn = new TreeMap<>();
        Scanner s = new Scanner(System.in);


        while(true){
            days = s.nextInt();

            if(days == 0)
                break;

            total = 0;
            urn.clear();

            for(int d = 0; d < days; d++) {
                // add new bills of this day
                bills = s.nextInt();
                for(int b = 0; b < bills; b++) {

                    int amount = s.nextInt();  // 1000000

                    if(urn.containsKey(amount)) {
                        int dups = urn.get(amount);
                        urn.put(amount, dups + 1);
                    }
                    else
                        urn.put(amount, 0);
                }

                //count total
                int min = urn.firstKey();
                int max = urn.lastKey();
                total += (max - min);


                //remove min and max from urn

                int min_dups = urn.get(min);
                if(min_dups == 0)
                    urn.remove(min);
                else
                    urn.put(min, min_dups - 1);

                if(urn.containsKey(max)) {
                    int max_dups = urn.get(max);
                    if (max_dups == 0)
                        urn.remove(max);
                    else
                        urn.put(max, max_dups - 1);
                }
            }

            System.out.println(total);
        }
    }
}
