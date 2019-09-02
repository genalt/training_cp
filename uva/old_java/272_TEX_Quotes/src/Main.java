import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        boolean open = true;

        while(s.hasNext()) {
            String current = s.nextLine();

            for(int i = 0; i < current.length(); i++) {
                char c = current.charAt(i);
                if(c == '"') {
                    if(open)
                        pw.print("``");
                    else
                        pw.print("''");
                    open = !open;
                }
                else
                    pw.print(c);


            }
            pw.println();
        }
        pw.flush(); pw.close();  s.close();
    }
}
