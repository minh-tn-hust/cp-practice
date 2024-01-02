/*
 * @lc app=leetcode id=931 lang=java
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int[][] dp = new int[n][n];


        for (int row = n - 1; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int left = Integer.MAX_VALUE;
                int right = Integer.MAX_VALUE;
                int center = Integer.MAX_VALUE;

                if (row + 1 >= n) {
                    left = 0;
                    right = 0;
                    center = 0;
                }  else {
                    if (col - 1 >= 0) {
                        left = dp[row + 1][col - 1];
                    }

                    if (col + 1 < n) {
                        right = dp[row + 1][col + 1];
                    }
                    center = dp[row + 1][col];
                }

                dp[row][col] = matrix[row][col] + Math.min(left, Math.min(center, right));
            }
        }

        int minFallingSum = Integer.MAX_VALUE;

        for (int col = 0; col < n; col++) {
            minFallingSum = Math.min(minFallingSum, dp[0][col]);
        }

        return minFallingSum;
    }
}
// @lc code=end

