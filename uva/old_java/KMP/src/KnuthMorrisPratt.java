import java.util.ArrayList;
import java.util.List;

public class KnuthMorrisPratt {

    private void substringPreprocess(String substring, int[] borders) {
        for(int i = 1; i < substring.length(); i++)
            if(substring.charAt(i) == substring.charAt(borders[i-1]))
                borders[i] = borders[i-1] + 1;
            else if (substring.charAt(i) == substring.charAt(0))
                borders[i] = 1;

        //for(int i = 0; i < substring.length(); i++)
        //    System.out.print(borders[i] + " ");

    }

    public List<Integer> search(String string, String substring) {
        int[] borders = new int[substring.length()];
        substringPreprocess(substring, borders);
        List<Integer> starts = new ArrayList<>();
        int i = 0, j = 0;

        while(i < string.length()) {
            if(string.charAt(i) != substring.charAt(j)) {
                System.out.println("Mismatch at j = " + j + " i = " + i);

                if (j > 0) {
                    System.out.println("New j =" + borders[j - 1]);
                    j = borders[j - 1];

                }
                else
                    i++;
            }
            else {
                i++;
                j++;

                if(j == substring.length()) {
                    starts.add(i - j);
                    j = borders[j - 1];
                }
            }
        }
        return starts;
    }

    // test
    public static void main(String[] args) {

        KnuthMorrisPratt kmp = new KnuthMorrisPratt();

        String text = "CNGJFOPLPOPABABDLLOPOABABABC";
        String pattern = "ABABC";
        List<Integer> starts = kmp.search(text, pattern);


        for(Integer i: starts) {
            System.out.println("Starts at " + i);
        }


    }
}
