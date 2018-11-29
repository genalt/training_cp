import java.util.*;


public class Main {
    public static void addTwo(List<Integer> list) {

    }

    public static void main(String[] args) {

        String [] countries = {"India", "Switzerland", "Italy"};


        Integer[] a = new Integer[6];
        int[] b = new int[6];
        Arrays.fill(b, 5);
        Arrays.fill(a, 5);


        List<Integer> list = new ArrayList<>();
        Collections.addAll(list, 1 ,2);
        list.addAll(Arrays.asList(a));
        //list.addAll(Arrays.asList(b));


        List<Integer> mylist = Collections.emptyList();
        mylist.add(2);
        //List<Integer> mylis2t = Collections.EMPTY_LIST;



        //mylist.a

        if(mylist instanceof ArrayList) {
            System.out.println("ArrayList!!!");
        }

        if(mylist instanceof List) {
            System.out.println("List");
        }

        System.out.println(mylist.getClass());

        for(Integer i: list)
            System.out.println(i);
    }

}
