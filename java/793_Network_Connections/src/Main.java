import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;


public class Main {

    static class UnionFind {
        private int[] parent;
        private int[] rank;

        UnionFind(int size){
            parent = new int[size + 1];
            rank = new int[size + 1];

            for(int i=1; i < size + 1; i++)
                parent[i] = i;
            Arrays.fill(rank, 0);
        }

        public int find(int val) {

            if(parent[val] != val)
                parent[val] = find(parent[val]);

            return parent[val];
        }

        public void union(int val1, int val2) {
            int p1 = find(val1);
            int p2 = find(val2);

            if(p1 == p2)
                return;

            if(rank[p1] > rank[p2])
                parent[p2] = p1;
            else {
                parent[p1] = p2;
                if(rank[p1] == rank[p2])
                    rank[p2]++;
            }

        }
    }


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        String l;
        br.readLine();
        String [] sp;
        int suc, unSuc, comps;
        for (int i = 0; i < t; i++){
            suc = 0;
            unSuc = 0;

            comps = Integer.parseInt(br.readLine());
            UnionFind network = new UnionFind(comps);


            while((l = br.readLine()) != null && !l.equals("")){
                sp = l.split(" ");
                int c1 = Integer.parseInt(sp[1]);
                int c2 = Integer.parseInt(sp[2]);
                if(sp[0].charAt(0) == 'c'){
                    network.union(c1, c2);
                }else{
                    if(network.find(c1) == network.find(c2))
                        suc++;
                    else
                        unSuc++;
                }
            }
            out.append(suc + "," + unSuc + "\n");
            if(i != t-1)
                out.append("\n");
        }
        System.out.print(out);
    }
}
