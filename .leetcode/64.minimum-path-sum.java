/*
 * @lc app=leetcode id=64 lang=java
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
    public int minPathSum(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;

        int[][] dp = new int[height + 1][width + 1];

        for (int i = 1; i <= width; i++) {
            dp[0][i] = 10000;
        }

        for (int i = 1; i <= height; i++) {
            dp[i][0] = 10000;
        }
        
        for (int r = 1; r <= height; r++) {
            for (int c = 1; c <= width; c++) {
                if (r == 1 && c == 1) {
                    dp[r][c] = grid[r - 1][c - 1];
                    continue;
                }
                dp[r][c] = Math.min(dp[r - 1][c], dp[r][c - 1]) + grid[r - 1][c - 1];
            }
        }


        return dp[height][width];
    }
}
// @lc code=end

