import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Arrays;


class EdmondsKarp {

    int maxFlow(int[][] capacity, int s, int t) {
        int[][] residual = new int[capacity.length][capacity[0].length];
        for(int i  = 0; i< capacity.length; i++)
            System.arraycopy(capacity[i],0, residual[i],0, capacity[i].length);


        int[] parent = new int[residual.length];
        int max_flow = 0;
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
            int min_flow, v;
            for (v = t, min_flow = residual[parent[v]][v]; parent[v] != -1; v = parent[v]) {
                if (residual[parent[v]][v] < min_flow)
                    min_flow = residual[parent[v]][v];
            }
            max_flow += min_flow;

            //update residual network and paths
            for (v = t; parent[v] != -1; v = parent[v]) {
                residual[parent[v]][v] -= min_flow;
                residual[v][parent[v]] += min_flow;
            }
        }
        return max_flow;
    }
}


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        EdmondsKarp ek = new EdmondsKarp();

        int nn = 1; //network number
        while (true) {

            if (nn > 1)
                System.out.println();
            int V = sc.nextInt();
            if (V == 0)
                break;

            int[][] capacity = new int[V][V];
            int s = sc.nextInt();
            int t = sc.nextInt();
            int E = sc.nextInt();

            while (E-- > 0) {
                int from = sc.nextInt();
                int to = sc.nextInt();
                int cap = sc.nextInt();

                capacity[from - 1][to - 1] += cap;
                capacity[to - 1][from - 1] += cap;
            }

            System.out.printf("Network %d\n", nn);
            System.out.printf("The bandwidth is %d.\n", ek.maxFlow(capacity, s - 1, t - 1));
            nn++;
        }
    }
}
