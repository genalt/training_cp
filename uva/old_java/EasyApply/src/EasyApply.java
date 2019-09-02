import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class EasyApply {

    private int[][] map;     // map with heights
    private int[][] path;    // DP table for path length
    private int[][] lowest;  // DP table for lowest reachable hill form the current one
    private int longestPath;
    private int steepestDrop;


    EasyApply(int R, int C) {
        map = new int[R][C];
        path = new int[R][C];
        lowest = new int[R][C];

    }

    private void DFS(int x, int y) {

        if (path[x][y] != 0)
            return;

        // go north
        if (x > 0 && map[x][y] > map[x - 1][y]) {
            DFS(x - 1, y);
            update(x, y, x - 1, y);
        }

        // go south
        if (x + 1 < map.length && map[x][y] > map[x + 1][y]) {
            DFS(x + 1, y);
            update(x, y, x + 1, y);
        }

        // go west
        if (y > 0 && map[x][y] > map[x][y - 1]) {
            DFS(x, y - 1);
            update(x, y, x, y - 1);
        }

        // go east
        if (y + 1 < map[0].length && map[x][y] > map[x][y + 1]) {
            DFS(x, y + 1);
            update(x, y, x, y + 1);
        }
    }

    private void update(int x, int y, int adj_x, int adj_y) {
        if (path[adj_x][adj_y] + 1 > path[x][y] ||
                path[adj_x][adj_y] + 1 == path[x][y] && lowest[adj_x][adj_y] < lowest[x][y]) {
            path[x][y] = path[adj_x][adj_y] + 1;
            lowest[x][y] = lowest[adj_x][adj_y];
        }

    }

    private void preprocess() {
        longestPath = steepestDrop = 0;

        // find longestPath possible path using DFS
        for (int x = 0; x < map.length; x++) {
            for (int y = 0; y < map[0].length; y++) {
                DFS(x, y);
                if (path[x][y] > longestPath ||
                        path[x][y] == longestPath && map[x][y] - lowest[x][y] > steepestDrop) {
                    longestPath = path[x][y];
                    steepestDrop = map[x][y] - lowest[x][y];
                }
            }
        }
    }

    public void set(int x, int y, int v) {
        map[x][y] = lowest[x][y] = v;
    }

    public List<Integer> getPath() {
        preprocess();
        return new ArrayList<Integer>() {{
            add(longestPath);
            add(steepestDrop);
        }};
    }


    // Tests
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int R = s.nextInt();
        int C = s.nextInt();

        EasyApply solution = new EasyApply(R, C);

        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                solution.set(r, c, s.nextInt());

        List<Integer> result = solution.getPath();
        System.out.println("Best path: length = " + (result.get(0) + 1) + ", steepest vertical drop = " + result.get(1));
    }
}
