import java.util.Scanner;
import java.util.Stack;

class Edit {
    Edit(String inName, int inPos, char inTo) {
        name = inName;
        pos = inPos;
        to = inTo;
    }

    public String name;
    public int pos;
    public char to;
}


public class Main {

    public static int score(char n, char m) {
        if(n == m)
            return 0;
        return 1;
    }

    public static void getDistance(String from, String to, int[][] dp) {
        // base cases i  - row, j - column
        for(int i = 0; i < dp.length; i++)
            dp[i][0] = i;

        for(int j = 0; j < dp[0].length; j++)
            dp[0][j] = j;


        for(int i = 1; i < dp.length; i++)
            for(int j = 1; j < dp[0].length; j++)
                dp[i][j] = Math.min(Math.min(dp[i-1][j-1] + score(from.charAt(i-1), to.charAt(j-1)), dp[i-1][j] + 1),
                                    dp[i][j-1] + 1);

        System.out.println(dp[from.length()][to.length()]);

        Stack<String> replaceStack = new Stack<>();
        Stack<Edit> insertDeleteStack = new Stack<>();

        int j = to.length();
        for(int i = from.length(); i > 0 || j > 0;) {

            // only insert is possible
            if(i == 0) {
                insertDeleteStack.push(new Edit("Insert", 1, to.charAt(j-1)));
                j--;
                continue;
            }

            // only delete is possible
            if(j == 0) {
                insertDeleteStack.push(new Edit("Delete ", i, 'd'));
                i--;
                continue;
            }


            // skip
            if(from.charAt(i-1) == to.charAt(j-1)) {
                j--; i--;
            }
            else {

                // replace operation
                if(dp[i][j] == dp[i-1][j-1] + 1) {
                    //System.out.println("Replace");
                    replaceStack.push("Replace " + i + "," + to.charAt(j - 1));
                    i--; j--;
                    continue;
                }

                // delete operation
                if(dp[i][j] == dp[i-1][j] + 1) {
                    insertDeleteStack.push(new Edit("Delete ", i, 'd'));
                    i--;
                    continue;
                }

                // insert operation
                if(dp[i][j] == dp[i][j-1] + 1) {
                    insertDeleteStack.push(new Edit("Insert", i + 1, to.charAt(j-1)));
                    j--;
                    continue;
                }
            }
        }

        int nop = 1;
        while(!replaceStack.isEmpty()) {
            System.out.println(nop + " " + replaceStack.pop());
            nop++;
        }

        int diff = 0;
        while(!insertDeleteStack.isEmpty()) {
            Edit cur =  insertDeleteStack.pop();

            if(cur.name.compareTo("Insert") == 0) {
                System.out.println(nop + " " + cur.name + " " + (cur.pos + diff) + "," + cur.to);
                diff++;
            }
            else {
                System.out.println(nop + " " + cur.name + " " + (cur.pos + diff));
                diff--;
            }

            nop++;
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int tc = 0;
        while(s.hasNextLine()) {
            if(tc > 0)
                System.out.println();
            String from = s.nextLine();
            String to = s.nextLine();

            int[][] dp = new int[from.length() + 1][to.length() + 1];

            getDistance(from, to, dp);

            tc++;
        }
    }
}
