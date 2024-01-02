/*
 * @lc app=leetcode id=378 lang=java
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
import java.util.*;
class Solution {
    PriorityQueue<Integer> smallestPeaking = new PriorityQueue<>();
    public int kthSmallest(int[][] matrix, int k) {
        int height = matrix.length;
        int width = matrix[0].length;

        for (int r = 0; r < height; r++) {
            for (int c = 0; c < width; c++) {
                smallestPeaking.add(matrix[r][c]);
            }
        }

        for (int i = 0; i < k - 1; i++) {
            smallestPeaking.poll();
        }

        return smallestPeaking.peek();
    }
}
// @lc code=end

