import java.util.Scanner;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;


class EdmondsKarp {

    int maxFlow(int[][] residual, int s, int t, int[] paths) {
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
                paths[v] = parent[v];
            }
        }
        return max_flow;
    }

    void printAllocations(int[][] capacity, int max_instances) {
        String program_names = "xABCDEFGHIJKLMNOPQRSTUVWXYZ"; // first character is dummy, indexing 1-26
        int[] paths = new int[38]; // will contain number of executing program on every computer, 1-26
        if (max_instances > 10) {
            System.out.println("!");
        } else {
            Arrays.fill(paths, -1);
            int res_flow = maxFlow(capacity, 0, 37, paths);
            if (res_flow == max_instances) {
                for (int i = 27; i < 37; i++) {
                    if (paths[i] == -1)
                        System.out.print("_");
                    else
                        System.out.print(program_names.charAt(paths[i]));
                }
            } else {
                System.out.print("!");
            }
            System.out.println();
        }
    }
}


public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        EdmondsKarp ek = new EdmondsKarp();

        String job;
        int[][] capacity = new int[38][38];
        for (int i = 27; i < 37; i++)
            capacity[i][37] = 1;
        int max_instances = 0; // maximum instances of all executing

        while (sc.hasNextLine()) {

            job  = sc.nextLine();

            if(!job.isEmpty()) {
                int program = job.charAt(0) - 'A' + 1;
                int instances = job.charAt(1) - '0';
                max_instances += instances;
                capacity[0][program] += instances;

                for (int i = 3; job.charAt(i) != ';'; i++)
                    capacity[program][job.charAt(i) - '0' + 27] = 1;
            }

            if (job.isEmpty() || !sc.hasNext()) {
                ek.printAllocations(capacity, max_instances);

                capacity = new int[38][38];
                for (int i = 27; i < 37; i++)
                    capacity[i][37] = 1;
                max_instances = 0;
            }
        }
    }
}
