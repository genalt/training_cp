import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int tc = s.nextInt();
        for(int i=0; i < tc; i++) {

            String res = s.next();
            if(res.equals("1") || res.equals("4") || res.equals("78")) {
                System.out.println("+");
            }
            else if(res.endsWith("35")) {
                System.out.println("-");
            }
            else if(res.startsWith("9") && res.endsWith("4") ) {
                System.out.println("*");
            }
            else  {
                System.out.println("?");
            }
        }
    }
}
