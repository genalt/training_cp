import static java.lang.System.out;
import java.util.Random;

public class Main {
    static int mso(long bs){
        //return 1..64
        int mso = -1;
        //long one = 1;
        for(int i = 0; i < 64; i++) {
            //out.println(Long.toBinaryString((1l << i)));
            if((bs & (1l << i)) > 0) {
                mso = i + 1;
            }
        }

        return mso;
    }




    static void pr64bin(long n) {
        int m = mso(n);
        for(int i = 0; i < 64 - m; i++)
            System.out.print("0");
        out.println(Long.toBinaryString(n));
    }


    public static void main(String[] args) {
        long bitset = 8;
        Random gen = new Random();
        for(int i=0; i< 10; i++)
            bitset |= (1l << gen.nextInt(63));


        //bitset |= (1l << 4);
        pr64bin(bitset);

        if((bitset & (1l << 4)) > 0)
            bitset -= (1l << 4);


        pr64bin(bitset);
        pr64bin(-bitset);

        pr64bin(bitset & (-bitset));

        pr64bin(-1);

        //a = a | (a + 1);

        //out.print(mso(bitset));


    }

}
