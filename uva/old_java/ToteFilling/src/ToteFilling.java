import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


class Goods implements Comparable<Goods> {
    public int id;
    public int volume;
    public int weight;
    public int price;

    Goods(int inId, int inPrice, int inVolume, int inWeight) {
        id = inId;
        volume = inVolume;
        weight = inWeight;
        price = inPrice;
    }

    @Override
    public int compareTo(Goods piece) {
        return this.volume - piece.volume;
    }
}


public class ToteFilling {
    static List<Goods> goodsList;
    static List<Integer> takenIDs;
    static int minWeight = Integer.MAX_VALUE;

    public static final int MAX_LENGTH = 45;
    public static final int MAX_WIDTH = 30;
    public static final int MAX_HEIGHT = 35;
    public static final int totalVolume = MAX_LENGTH * MAX_WIDTH * MAX_HEIGHT;

    static void restorePath(byte[][] path, int i, int j, int curWeight, List<Integer> tmpIDs) {
        while (path[i][j] == 0 && i > 0)  // if do not take i-th element, just skip it
            i--;

        // base of recursion
        if (i == 0) {
            if (path[0][j] == 1) {
                tmpIDs.add(0);
                curWeight += goodsList.get(0).weight;
            }

            if (curWeight < minWeight) {
                minWeight = curWeight;
                takenIDs.clear();
                for (Integer id : tmpIDs)
                    takenIDs.add(id);
            }
            return;
        }

        if (path[i][j] == 2) {
            tmpIDs.add(i);
            restorePath(path, i - 1, j - goodsList.get(i).volume, curWeight + goodsList.get(i).weight, tmpIDs);
            tmpIDs.remove(tmpIDs.size() - 1);

            restorePath(path, i - 1, j, curWeight, tmpIDs);

        } else if (path[i][j] == 1) {
            tmpIDs.add(i);
            restorePath(path, i - 1, j - goodsList.get(i).volume, curWeight + goodsList.get(i).weight, tmpIDs);
            tmpIDs.remove(tmpIDs.size() - 1);
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        goodsList = new ArrayList<>();

        //read input
        while (br.ready()) {
            String goodParameters = br.readLine();
            int[] parameters = new int[6];

            int i = 0;
            for (String p : goodParameters.split(",")) {
                parameters[i] = Integer.parseInt(p);
                i++;
            }

            if (parameters[2] <= MAX_LENGTH && parameters[3] <= MAX_WIDTH && parameters[4] <= MAX_HEIGHT)
                goodsList.add(new Goods(parameters[0], parameters[1], parameters[2] * parameters[3] * parameters[4], parameters[5]));
        }
        br.close();

        if (goodsList.isEmpty())
            return;

        Collections.sort(goodsList);

        int[][] DP = new int[2][totalVolume + 1];
        byte[][] path = new byte[goodsList.size()][totalVolume + 1];


        // use DP to fill table
        for (int j = 0; j <= totalVolume; j++) {
            if (j >= goodsList.get(0).volume) {
                DP[0][j] = goodsList.get(0).price;
                path[0][j] = 1;
            }
        }
        int cur_row = 1;
        for (int i = 1; i < goodsList.size(); i++, cur_row = 1 - cur_row) {

            for (int j = 1; j <= totalVolume; j++) {
                int prevPrice = DP[1 - cur_row][j];

                if (j - goodsList.get(i).volume >= 0) {
                    int newPrice = DP[1 - cur_row][j - goodsList.get(i).volume] + goodsList.get(i).price;

                    if (newPrice > prevPrice) {
                        DP[cur_row][j] = newPrice;
                        path[i][j] = 1;   //take i-th

                    } else if (newPrice < prevPrice) {
                        DP[cur_row][j] = prevPrice;

                    } else {
                        DP[cur_row][j] = prevPrice;
                        path[i][j] = 2;  //i-th can be taken or not
                    }
                } else {
                    DP[cur_row][j] = prevPrice;
                }
            }
        }

        System.out.println("Max price is " + DP[1 - cur_row][totalVolume]);

        takenIDs = new ArrayList<>();
        List<Integer> tmpList = new ArrayList<>();
        restorePath(path, goodsList.size() - 1, totalVolume, 0, tmpList);

        System.out.println("List of taken goods: ");
        for (Integer g : takenIDs)
            System.out.print(goodsList.get(g).id + " + ");
    }
}
