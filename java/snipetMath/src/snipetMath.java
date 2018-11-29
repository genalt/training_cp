import java.util.Random;

public class snipetMath {

    // tests
    public static void main(String[] args) {
        System.out.println(Math.PI);
        System.out.println(Math.E);

        Random gen = new Random();
        for(int i=0; i < 10; i++)
            System.out.println(Math.abs(gen.nextInt()));

        for(int i=0; i < 10; i++)
            System.out.println(gen.nextInt(Integer.MAX_VALUE));


        System.out.println(Math.sqrt(144));
        System.out.println(Math.pow(2, 10));
    }
}
