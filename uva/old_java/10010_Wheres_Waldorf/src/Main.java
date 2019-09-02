import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException{
        final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //final BufferedReader in = new BufferedReader(new FileReader("in.txt"));
        int numTestCases = Integer.parseInt(in.readLine());
        for(int testCase = 1; testCase <= numTestCases; testCase++){
            // read blank line
            in.readLine();

            String[] dimensions = in.readLine().split(" ");
            int numRows = Integer.parseInt(dimensions[0]);
            int numCols = Integer.parseInt(dimensions[1]);
            char[][] grid = new char[numRows][numCols];

            for(int row = 0; row < numRows; row++){
                char[] chars = in.readLine().trim().toCharArray();
                for(int col = 0; col < chars.length; col++){
                    grid[row][col] = Character.toLowerCase(chars[col]);
                }
            }

            int numWords = Integer.parseInt(in.readLine().trim());
            for(int w = 0; w < numWords; w++){
                String word = in.readLine().trim();
                int[] coords = findString(grid, word.toLowerCase());
                System.out.println(coords[0] + " " + coords[1]);
            }

            if(testCase < numTestCases)
                System.out.println();
        }
    }

    static int[] findString(char[][] grid, String string){
        for(int row = 0; row < grid.length; row++){
            for(int col = 0; col < grid[row].length; col++){
                if(grid[row][col] == string.charAt(0)){ // char in this grid position is the same as the first character of the string
                    if(checkEast(grid, string, row, col) ||
                            checkNorth(grid, string, row, col) ||
                            checkNorthEast(grid, string, row, col) ||
                            checkNorthWest(grid, string, row, col) ||
                            checkSouth(grid, string, row, col) ||
                            checkSouthEast(grid, string, row, col) ||
                            checkSouthWest(grid, string, row, col) ||
                            checkWest(grid, string, row, col))
                        return new int[] {row + 1, col + 1};
                }
            }
        }

        return new int[] {0, 0}; // should never be reached as the string appears at least once in the grid
    }

    static boolean checkNorth(char[][] grid, String string, int row, int col){
        int i = 0;
        for(; row >= 0 && i < string.length() &&
                grid[row][col] == string.charAt(i); row--, i++);
        return (i == string.length());
    }

    static boolean checkSouth(char[][] grid, String string, int row, int col){
        int i = 0;
        for(; row < grid.length && i < string.length() &&
                grid[row][col] == string.charAt(i); row++, i++);
        return (i == string.length());
    }

    static boolean checkWest(char[][] grid, String string, int row, int col){
        int i = 0;
        for(; col >= 0 && i < string.length() &&
                grid[row][col] == string.charAt(i); col--, i++);
        return (i == string.length());
    }

    static boolean checkEast(char[][] grid, String string, int row, int col){
        int i = 0;
        for(; col < grid[row].length && i < string.length() &&
                grid[row][col] == string.charAt(i); col++, i++);
        return (i == string.length());
    }

    static boolean checkNorthEast(char[][] grid, String string, int row, int col){
        int i = 0;
        for(; row >= 0 && col < grid[row].length &&
                i < string.length() && grid[row][col] == string.charAt(i); row--, col++, i++);
        return (i == string.length());
    }

    static boolean checkNorthWest(char[][] grid, String string, int row, int col){
        int i = 0;
        for(; row >= 0 && col >= 0 && i < string.length() &&
                grid[row][col] == string.charAt(i); row--, col--, i++);
        return (i == string.length());
    }

    static boolean checkSouthWest(char[][] grid, String string, int row, int col){
        int i = 0;
        for(; row < grid.length && col >= 0 && i < string.length() &&
                grid[row][col] == string.charAt(i); row++, col--, i++);
        return (i == string.length());
    }

    static boolean checkSouthEast(char[][] grid, String string, int row, int col){
        int i = 0;
        for(; row < grid.length && col < grid[row].length && i < string.length() &&
                grid[row][col] == string.charAt(i); row++, col++, i++);
        return (i == string.length());
    }
}