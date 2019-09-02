import java.util.Arrays;

public class BellmanFord {

    public boolean sssp(int[][] adjMatrix, int s, int[] lengths, int[] parent) {

        Arrays.fill(lengths, 1000000);
        lengths[s] = 0;

        for(int p = 0; p < parent.length; p++)
            parent[p] = p;

        System.out.println(Arrays.toString(lengths));
        System.out.println(Arrays.toString(parent));

        for(int i = 0; i < adjMatrix[0].length; i++) {

            for (int v = 0; v < adjMatrix[0].length; v++) {
                for (int u = 0; u < adjMatrix[v].length; u++) {

                    if (adjMatrix[v][u] != 0 && lengths[v] + adjMatrix[v][u] < lengths[u]) {
                        lengths[u] = lengths[v] + adjMatrix[v][u];
                        parent[u] = v;
                    }
                }
            }
        }


        //check negative cycle
        for (int v = 0; v < adjMatrix[0].length; v++) {
            for (int u = 0; u < adjMatrix[v].length; u++) {

                if (adjMatrix[v][u] != 0 && lengths[v] + adjMatrix[v][u] < lengths[u]) {
                    return false;

                }
            }
        }

        System.out.println(Arrays.toString(lengths));
        System.out.println(Arrays.toString(parent));
        return true;
    }

    //tests
    public static void main(String[] args) {
        BellmanFord bf = new BellmanFord();

        int[][] adjMatrix = {
                {0,0,0,0,1},
                {0,0,0,3,3},
                {6,2,0,7,0},
                {0,0,0,0,5},
                {0,0,0,0,0}

        };

        int[] length = new int[adjMatrix[0].length];
        int[] parent = new int[adjMatrix[0].length];

        boolean ok = bf.sssp(adjMatrix, 2, length, parent);

        if(!ok) {
            System.out.println("Negative cycle!");
        }
        else {

            for(int i = 0; i< adjMatrix[0].length; i++) {

                System.out.printf("to vertex %d length %d\n", i, length[i]);
                System.out.print(i + " <- ");
                int p = parent[i];

                while(true) {

                    if(p == 2) {
                        System.out.print(" 2 ");
                        break;
                    }
                    else {
                        System.out.print(p + " <- ");
                        p = parent[p];
                    }
                }
                System.out.println();

            }
        }
    }
}
