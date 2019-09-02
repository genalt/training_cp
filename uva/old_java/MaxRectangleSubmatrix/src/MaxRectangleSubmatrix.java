public class MaxRectangleSubmatrix {



    static int getOneSubmatrix(int[][] matrix) {

        int r = matrix.length;
        int c = matrix[0].length;

        int max_area = 0;



        for (int i = 1; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (matrix[i][j] != 0)
                    matrix[i][j] += matrix[i -1][j];



        /*

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j)
                System.out.print(matrix[i][j] + " ");
            System.out.println();
        }

        */



        return 0;
    }

    public static void main(String[] args) {

        int[][] matrix = {{0, 0, 0, 1, 1},
                          {1, 0, 0, 1, 0}

        };

        getOneSubmatrix(matrix);

    }
}
