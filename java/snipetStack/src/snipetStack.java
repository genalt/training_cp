import java.util.Stack;
import java.util.ArrayDeque;

public class snipetStack {


    public static void main(String args[]) {
        // creating stack
        Stack<String> st = new Stack<>();

        // populating stack
        st.push("Java");
        st.push("Source");
        st.push("code");

        // removing top object
        System.out.println("Removed object is: "+st.peek());

        // elements after remove
        System.out.println("Elements after remove: "+st);
    }

}
