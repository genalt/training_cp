import java.util.*;

public class Solution {
    static boolean isOneEdit(String word1, String word2) {
        if (Math.abs(word1.length() - word2.length()) > 1)
            return false;

        int numberEdits = 0;

        if(word1.length() == word2.length()) {
            for(int i = 0; i < word1.length() && numberEdits < 2; i++) {
                char ch1 = word1.charAt(i);
                char ch2 = word2.charAt(i);

                if(ch1 != ch2)
                    numberEdits++;
            }
        } else {
            if(word1.length() < word2.length()) {
                String tmp = word1;
                word1 = word2;
                word2 = tmp;
            }

            int p1 = 0;
            int p2 = 0;

            while(p1 < word1.length() && p2 < word2.length() && numberEdits < 2) {
                char ch1 = word1.charAt(p1);
                char ch2 = word2.charAt(p2);

                if(ch1 == ch2) {
                    p1++;
                    p2++;
                } else {
                    p1++;
                    numberEdits++;
                }
            }
        }


        return numberEdits < 2;
    }

    static boolean isOneEditEquals(String word1, String word2) {
        int numberEdits = 0;
        for(int i = 0; i < word1.length() && numberEdits < 2; i++)
            if(word1.charAt(i) != word2.charAt(i))
                numberEdits++;
        return numberEdits < 2;
    }


    public static void main(String[] args) {

        System.out.println("test");



    }
}
