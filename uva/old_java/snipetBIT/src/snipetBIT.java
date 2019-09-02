

class BinaryIndexedTree {
    int[] ft;

    BinaryIndexedTree(int[] a) {
        ft = new int[a.length];
        for(int i = 0; i < a.length; i++)
            update(i, a[i]);
    }

    void update(int i, int v) {
        for(int j = i; j < ft.length; j = j | (j+1)){
            ft[j] += v;
        }
    }

    int sum(int r) {
        int res = 0;
        for(int i=r; i>=0; i = (i & (i+1)) - 1)
            res += ft[i];
        return res;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
}

class FenwickTree {

    public int[] ft;

    public void update(int v, int i){
        i++;
        while(i < ft.length){
            ft[i] += v;
            i = getNext(i);
        }
    }

    public int sum(int i){
        i = i + 1;
        int sum = 0;
        while(i > 0){
            sum += ft[i];
            i = i - (i & -i);
        }
        return sum;
    }

    public int sum(int l, int r){
       return sum(r) - sum(l - 1);

    }

    FenwickTree(int input[]){
        ft = new int[input.length+1];

        for(int i=0; i < input.length; i++){
            update(input[i], i);
        }
    }

    private int getParent(int index){
        return index - (index & -index);
    }

    private int getNext(int index){
        return index + (index & -index);
    }
}



public class snipetBIT {

    // tests


    public static void main(String[] args) {
        int[] a = {0, 1, 2, 1, 0, -1, 1, 1, 0, 2, 3, -4, 6, 3}; // 8

        int r1 = 6;
        int l1 = r1 + (r1 & -r1);
        int l2 = r1 | (r1 + 1);

        System.out.println(Integer.toBinaryString(r1));
        System.out.println(Integer.toBinaryString(l1));
        System.out.println(Integer.toBinaryString(l2));



    }
}
