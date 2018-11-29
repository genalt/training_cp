import java.util.Scanner;


class RandomizedMultiset {

    private class Node {
        long key;
        long duplicates;
        long nodes;

        Node left;
        Node right;

        public Node(long inKey) {
            this.key = inKey;
            this.nodes = 1;
            this.duplicates = 0;
        }
    }

    private Node root;
    private long leftShifts;
    private long minKey;
    private long maxKey;


    private long size(Node x) {
        if (x == null)
            return 0;
        else
            return x.nodes + x.duplicates;
    }

    public long insert(long key) {
        leftShifts = 0;

        // first node in the Tree
        if (root == null) {
            root = new Node(key);
            minKey = maxKey = key;
        } else {

            if (key > maxKey && Math.random() > 0.5) {       // make new root, if we have max key, with probability 50%
                Node new_root = new Node(key);
                new_root.nodes = size(root) + 1;
                new_root.left = root;
                root = new_root;
            } else if (key < minKey && Math.random() > 0.5) { // make new root, if we have min key, with probability 50%
                Node new_root = new Node(key);
                new_root.nodes = size(root) + 1;
                leftShifts += size(root);
                new_root.right = root;
                root = new_root;
            } else {
                insert(root, key); // count shifts and insert new Node
            }


            if (key < minKey)
                minKey = key;

            if (key > maxKey)
                maxKey = key;
        }

        return leftShifts;
    }



    private void insert(Node node, Long key) {

        // insert into left subtree
        if (key < node.key) {
            leftShifts += node.duplicates + size(node.right) + 1;

            if (node.left == null)
                node.left = new Node(key); // insert new node in case if we do not make new root
            else
                insert(node.left, key);
        }

        //insert into right subtree
        else if (key > node.key) {
            if (node.right == null)
                    node.right = new Node(key); // insert new node in case if we do not make new root
            else
                insert(node.right, key);
        }

        // increase duplicates
        else {
            leftShifts += size(node.right);
            node.duplicates++;
        }

        node.nodes = size(node.left) + size(node.right) + 1;
    }
}


public class Test4 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        long test = sc.nextLong();
        while(test-- > 0){
            RandomizedMultiset s = new RandomizedMultiset();
            long leftShifts = 0;
            long elements = sc.nextLong();
            while(elements-- > 0) {
                leftShifts += s.insert(sc.nextLong());
            }
            System.out.println(leftShifts);
        }
    }
}