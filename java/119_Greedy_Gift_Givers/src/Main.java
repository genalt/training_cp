import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int processed = 0;

        while(s.hasNext()) {
            int num = s.nextInt();
            //System.out.println("in group: " + num);

            HashMap<String, Integer> group = new HashMap<>();
            ArrayList<String> all_names = new ArrayList<>();

            // fill the group
            for(int i=0; i< num; i++) {
                String name = s.next();
                group.put(name, 0);
                all_names.add(name);
                //System.out.println(name);
            }
            // spend money
            for(int i=0; i < num; i++) {
                String name = s.next(); // who spend
                int total_amount  = s.nextInt(); //how much
                int presenters_number = s.nextInt();
                if(presenters_number == 0)
                    continue;
                int amount_per_one = total_amount/presenters_number;

                total_amount -= (total_amount % presenters_number);
                group.put(name, group.get(name) - total_amount);

                for(int p=0; p < presenters_number; p++) {
                    name = s.next();
                    group.put(name, group.get(name) + amount_per_one);
                }
            }

            if(processed != 0) {
                System.out.println();
            }
            else {
                processed++;
            }
            for(String n: all_names) {
                System.out.println(n + " " + group.get(n));
            }


        }
    }
}
