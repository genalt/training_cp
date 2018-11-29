import java.util.Arrays;
import java.util.StringTokenizer;


public class snipetString {
    public static void main(String[] args) {
        // char array
        char[] cha = {'a', 'b', 'z'};
        char[] cha2 = new char[5];
        Arrays.fill(cha2, 'm');
        char[] cha3 = Arrays.copyOf(cha, cha.length); // O(n)
        char[] cha4 = Arrays.copyOfRange(cha, 1, cha.length); // O(n)

        // String class, immutable object
        String S1 = new String();        // declares an empty string. O(1)
        String S2 = new String("Hello"); // declares string initialized to "Hello"
        String S3 = new String(cha2);
        String S4 = "Some str";
        String S5 = String.format("%d", 55);

        // StringBuilder for mutable string.
        StringBuilder B1 = new StringBuilder();        // empty string
        StringBuilder B2 = new StringBuilder("Hello"); // stringbuilder initialized to "Hello".

        // get length, O(1)
        S1.length();
        B1.length();
        int len = cha.length;

        // get charachter O(1)
        S2.charAt(2);
        B2.charAt(1);
        char c = cha2[0];

        // concatenation
        S3 = S2.concat(" world"); // O(n) operation. Creates another copy of the string as string is immutable.
        S3 = S1 + S4;
        B2.append(" world");      // O(z) operation where z is the length of the string being appended. Much more efficient.
        // public static void arraycopy(Object src, int srcPos, Object dest, int destPos, int length) O(n)
        char[] nch = new char[cha.length + cha2.length];
        System.arraycopy(cha, 0, nch, 0, cha.length);
        System.arraycopy(cha2, 0, nch, cha.length, cha2.length);

        // reverse
        String RS1 = new StringBuilder(S1).reverse().toString();
        StringBuilder B3 = B1.reverse();

        char[] rev = new char[cha.length];
        System.arraycopy(cha, 0, rev, 0, cha.length);
        for(int l=0, r = cha.length - 1; l < cha.length/2; l++) {
            char tmp = rev[l];
            rev[l] = rev[r];
            rev[r] = tmp;
        }
        StringBuilder tmp = new StringBuilder();
        rev = tmp.append(cha).reverse().toString().toCharArray();

        // substrings
        String sub1 = B2.substring(0, 2);
        String sub3 = B2.substring(2);

        // find substring
        boolean b = B1.toString().startsWith("Mad");
        boolean s = S1.endsWith("sub2");
        s = S3.contains("word");
        s = S3.indexOf("world") >= 0;
        s = S3.lastIndexOf("world") >=0;
        b = B1.indexOf("dfa") >= 0;
        b = B1.lastIndexOf("dfa") >= 0;


        // replacement
        String tr = S3.trim();
        String a = S2.replace("o", "a");

        //for String replaceAll(String regex, String replacement)
        //for String replaceFirst(String regex, String replacement)

        String a2 = B2.replace(6, B2.length(), "galt").toString();


        // tockenizer
        String st = "new stinrg! for tockenize! 24";
        StringTokenizer tok = new StringTokenizer(st, "!", false);
        String[] starr = st.split("!");

        for(int i =0; i< starr.length; i++) {
            System.out.println(starr[i].trim());
        }

        while(tok.hasMoreTokens()) {
            System.out.println(tok.nextToken().trim());
        }

        System.out.println("-----------------");
        String for_split = "new stinrg! for  tock'enize! 24, 34";
        for(String spl: for_split.split("[!?,.\\ \\']")) {
            System.out.println(spl);
        }

    }
}