import java.util.Map;
import java.util.HashMap;


public class Trie {

    public class TrieNode {
        Map<Character, TrieNode> children;
        int numberTerminates;  // if more than 1 this node is a leaf

        // construct new TrieNode
        TrieNode() {
            children = new HashMap<>();
        }
    }

    // root of the tree
    TrieNode root;

    // constructor
    Trie() {
        root = new TrieNode();
    }


    void addWord(String word) {

        TrieNode currentNode = root;
        TrieNode nextNode = null;

        for (int i = 0; i < word.length(); i++) {

            Character currentChar = word.charAt(i);

            if (currentNode.children.containsKey(currentChar)) {
                nextNode = currentNode.children.get(currentChar);
            } else {
                nextNode = new TrieNode();
                currentNode.children.put(currentChar, nextNode);
            }

            if (i == word.length() - 1)
                currentNode.numberTerminates++;

            currentNode = nextNode;
        }
    }

    int contains(String word) {
        TrieNode currentNode = root;
        TrieNode nextNode = null;

        for (int i = 0; i < word.length(); i++) {

            Character currentChar = word.charAt(i);

            //System.out.println("In current node " + currentNode.children.size() + " children");

            if (currentNode.children.containsKey(currentChar)) {
                nextNode = currentNode.children.get(currentChar);
            } else {
                return 0;
            }

            if (i == word.length() - 1)
                return currentNode.numberTerminates;

            currentNode = nextNode;
        }

        // if word is empty we never step into for loop
        return 0;
    }


    public static void main(String[] args) {

        Trie myTrie = new Trie();

        myTrie.addWord("one");
        myTrie.addWord("ode");
        System.out.println(myTrie.contains("on"));

    }


}
