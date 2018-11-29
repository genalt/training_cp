import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        boolean end = false;
        int num = 1;

        while(!end) {
            String w = s.nextLine();

            String ans = String.format("Case %d: ", num);

            switch (w) {
                case("#"): end = true; break;
                case("HELLO"): System.out.println(ans + "ENGLISH"); break;
                case("HOLA"): System.out.println(ans + "SPANISH"); break;
                case("HALLO"): System.out.println(ans + "GERMAN"); break;
                case("BONJOUR"): System.out.println(ans + "FRENCH"); break;
                case("CIAO"): System.out.println(ans + "ITALIAN"); break;
                case("ZDRAVSTVUJTE"): System.out.println(ans + "RUSSIAN"); break;
                default: System.out.println(ans + "UNKNOWN"); break;




            }
            num++;
        }
    }
}
