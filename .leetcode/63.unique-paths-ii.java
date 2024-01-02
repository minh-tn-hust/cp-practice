/*
 * @lc app=leetcode id=63 lang=java
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
    public static final int OBSTACLE = 1;
    public static final int PATH = 0;
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int width = obstacleGrid[0].length;
        int height = obstacleGrid.length;

        int[][] dp = new int[height][width];
        dp[0][0] = 1;

        for (int r = 0; r < height; r++) {
            for (int c = 0; c < width; c++) {
                if (obstacleGrid[r][c] == OBSTACLE) {
                    dp[r][c] = 0;
                } else {
                    if (r - 1 >= 0) {
                        dp[r][c] += dp[r - 1][c];
                    }

                    if (c - 1 >= 0) {
                        dp[r][c] += dp[r][c - 1];
                    }
                }
            }
        }

        return dp[height - 1][width - 1];
    }
}
// @lc code=end

