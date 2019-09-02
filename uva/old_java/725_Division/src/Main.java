import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();

        boolean first = true;

        while(N != 0) {

            int abcde, fghij, tmp;
            boolean[] num;
            boolean was_found = false;

            if(!first) System.out.println();

            for(fghij = 1234; fghij <= 98765; fghij++) {

                abcde = fghij*N;

                if(abcde > 98765)
                    break;

                num =  new boolean[10];
                boolean correct = true;

                //check abcde
                tmp = abcde;
                for(int i=0; i < 5 && correct; i++) {
                    int d = tmp % 10;

                    if(!num[d]) {
                        //System.out.printf("checking %d from abcde = %d\n", d, abcde);
                        num[d] = true;
                    }
                    else
                        correct = false;

                    tmp = tmp / 10;

                }

                tmp = fghij;
                for(int i=0; i < 5 && correct; i++) {
                    int d = tmp % 10;

                    if(!num[d]) {
                        //System.out.printf("checking %d from fghij = %d\n", d, fghij);
                        num[d] = true;
                    }
                    else
                        correct = false;

                    tmp = tmp / 10;
                }

                if(correct) {
                    System.out.printf("%05d / %05d = %d\n", abcde, fghij, N);
                    was_found = true;
                }

            }

            if(!was_found)
                System.out.printf("There are no solutions for %d.\n", N);

            N = s.nextInt();
            first = false;
        }
    }

}
