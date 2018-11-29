import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Arrays;


class EdmondsKarp {

    void maxFlow(long[][] capacity, int s, int t, int[] cut) {
        long[][] residual = new long[capacity.length][capacity[0].length];
        for(int i  = 0; i< capacity.length; i++)
            System.arraycopy(capacity[i],0, residual[i],0, capacity[i].length);

        Arrays.fill(cut, t);

        int[] parent = new int[residual.length];
        boolean sink_reached;
        Queue<Integer> q = new LinkedList<>();

        while (true) {
            Arrays.fill(parent, -1);
            q.clear();
            q.add(s);

            sink_reached = false;
            // find augmenting path using BFS, visiting every edge in Adjacency Matrix, takes O(V^2)
            while (!q.isEmpty() && !sink_reached) {
                int u = q.remove();
                for (int v = 0; v < residual[u].length; v++) {
                    if (v != s && residual[u][v] > 0 && parent[v] == -1) {
                        parent[v] = u;
                        if (v == t) {
                            sink_reached = true;
                            break; // immediately stop BFS if we already reach the sink t
                        }
                        q.add(v);
                    }
                }
            }
            // stop if cannot add new flow
            if (!sink_reached)
                break;

            // find min edge in a new augmenting path
            long min_flow;
            int v;
            for (v = t, min_flow = residual[parent[v]][v]; parent[v] != -1; v = parent[v]) {
                if (residual[parent[v]][v] < min_flow)
                    min_flow = residual[parent[v]][v];
            }

            //update residual network and paths
            for (v = t; parent[v] != -1; v = parent[v]) {
                residual[parent[v]][v] -= min_flow;
                residual[v][parent[v]] += min_flow;
            }
        }
        dfsFindCut(residual, s, cut);


    }

    void dfsFindCut(long[][] residual, int u, int[] cut) {
        cut[u] = 0;
        for(int v = 0; v < residual[u].length; v++) {
            if(cut[v] != 0 && residual[u][v] > 0)
                dfsFindCut(residual, v, cut);
        }
    }
}


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        EdmondsKarp ek = new EdmondsKarp();

        int t = 1;
        while(true) {
            if(t != 1)
                System.out.println();

            int n = sc.nextInt();
            if(n == 0)
                break;
            int m = sc.nextInt();
            long[][] capacity = new long[n][n];
            int[] cut = new int[n];

            while(m-- > 0) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                long w = sc.nextLong();

                capacity[u-1][v-1] = w;
                capacity[v-1][u-1] = w;
            }

            ek.maxFlow(capacity, 0, 1, cut);

            for(int u = 0; u < capacity.length; u++)
                for(int v = 0; v < capacity.length; v++)
                    if(capacity[u][v] > 0 && cut[u] == 0 && cut[v] == 1)
                        System.out.println((u + 1) + " " + (v+1));

            t++;

        }
    }
}
