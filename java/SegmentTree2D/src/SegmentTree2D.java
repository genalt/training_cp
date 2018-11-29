public class SegmentTree2D {

    /* Ideas how to make it:

    I:
        Implement as an array of one dimension Segment Trees. So for Array[4][5] it will be something like:

        St[0] = SegmentTree for Array[0][0] .. Array[0][4]
        St[1] = SegmentTree for Array[1][0] .. Array[1][4]
        ...
        St[3] = SegmentTree for Array[3][0] .. Array[1][5]


        space complexity is: O(N*4M)
        time complexity is: O(N*logM)

        and choose N as a minimum of number columns and rows in the original matrix.

    II: Implement as a Quad Tree


     */

}
