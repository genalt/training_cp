import java.util.LinkedList;
import java.util.Queue;
import java.util.Arrays;


public class EdmondsKarp {

    int maxFlow(int[][] residual, int s, int t) {
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

            //update residual network
            for (v = t; parent[v] != -1; v = parent[v]) {
                residual[parent[v]][v] -= min_flow;
                residual[v][parent[v]] += min_flow;
            }
        }
        return max_flow;
    }

    // test
    public static void main(String[] args) {

        EdmondsKarp ek = new EdmondsKarp();

        int[][] capacity = { {0, 20, 10, 0},
                             {20, 0, 5, 10},
                             {10, 5, 0, 20},
                             {0, 0, 0, 0}
                            };

        System.out.println(ek.maxFlow(capacity, 0, 3));
    }

}
