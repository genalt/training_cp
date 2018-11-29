import java.util.ArrayList;
import java.util.HashMap;
import java.util.Arrays;


public class UnionFindDisjointSets {
    private int[] parent;
    private int[] rank;

    UnionFindDisjointSets(int[] a){
        parent = new int[a.length];
        rank = new int[a.length];
        Arrays.fill(parent, -1);
        Arrays.fill(rank, 0);
    }

    public int find(int val) {

        if(parent[val] != -1)
            parent[val] = find(parent[val]);

        return val;
    }

    public void union(int val1, int val2) {
       int p1 = find(val1);
       int p2 = find(val2);

       if(p1 == p2)
           return;

       if(rank[p1] > rank[p2])
           parent[val2] = p1;
       else {
           parent[val1] = p2;
           if(rank[p1] == rank[p2])
               rank[p2]++;
       }

    }

}
