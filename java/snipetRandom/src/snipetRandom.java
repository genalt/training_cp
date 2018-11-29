import java.util.Random;


public class snipetRandom {


    public static void main(String[] args) {

        Random generator = new Random();

        for (int i = 0; i< 10; i++) {
            System.out.println(generator.nextLong());
        }

        for (int i = 0; i< 10; i++) {
            System.out.println(generator.nextInt());
        }

        for (int i = 0; i< 10; i++) {
            System.out.println(generator.nextDouble());
        }

        for (int i = 0; i< 10; i++) {
            System.out.println(Math.random());
        }

    }

}
