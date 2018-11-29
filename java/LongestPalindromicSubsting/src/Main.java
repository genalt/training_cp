import java.util.Scanner;

public class Main {

    static String manachers(String A) {
        // transform the input A
        StringBuilder sb = new StringBuilder();
        sb.append("$#");
        for(int i = 0; i < A.length(); i++) {
            sb.append(A.charAt(i));
            sb.append('#');
        }
        sb.append('@');
        String new_text = sb.toString();

        //System.out.println(new_text);


        int[] P = new int[new_text.length()];

        // information about the last founded palindrome
        int C = 0; // center
        int R = 0; // right boundary

        int mirror = 0; // mirror for current index
        int max_length = 0;
        int max_center = 0;

        for (int i = 1; i < new_text.length() - 1; i++) {
            mirror = i - 2 * (i - C);
            if (i < R)
                P[i] = Math.min(P[mirror], R - i);

            while(new_text.charAt(i + (1 + P[i])) == new_text.charAt(i - (1 + P[i])))
                P[i]++;

            // found new max palindrome, update information
            if (P[i] > max_length) {
                max_length = P[i];
                max_center = i;
            }


            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }

        }

        max_length *= 2;
        if (new_text.charAt(max_center) == '#')
            max_length++;

        //System.out.println("max length = " + max_length + " " + max_center);
        int max_start = max_center - max_length/2;

        String maxPalindrome = new_text.substring(max_start, max_start + max_length);

        sb.delete(0, sb.length());

        for(int i = 0; i < maxPalindrome.length(); i++)
            if(maxPalindrome.charAt(i) != '#')
                sb.append(maxPalindrome.charAt(i));

        //System.out.println(maxPalindrome);
        //System.out.println(sb.toString());

        //return A.substring(max_center, max_center + max_length);
        return sb.toString();
    }

    static String longestPalindromicSubstringDP(String text) {

        if(text.isEmpty())
            return "";

        boolean[][] dp = new boolean[text.length()][text.length()];

        int max_length = 0;
        int start = 0;

        // base case length = 1
        for (int i = 0; i < text.length(); i++)
            dp[i][i] = true;

        // base case length = 2
        for (int i = 0; i < text.length() - 1; i++)
            if (text.charAt(i) == text.charAt(i + 1)) {
                dp[i][i + 1] = true;
                start = i;
                max_length = 1;
            }

        // counting all length >= 3
        for (int l = 2; l < text.length(); l++)
            for (int i = 0; i + l < text.length(); i++)
                if (text.charAt(i) == text.charAt(i + l) && dp[i + 1][i + l - 1]) {
                    dp[i][i + l] = true;

                    if (l > max_length || (l == max_length && i < start)) {
                        max_length = l;
                        start = i;
                    }
                }
        return text.substring(start, start + max_length + 1);
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String pal = s.next();
        //System.out.println(longestPalindromicSubstringDP(pal));
        System.out.println(manachers(pal));
    }
}
