/*
 * @lc app=leetcode id=221 lang=java
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
    int[][] dp;
    public boolean isSquareArea(int area) {
        int edge = (int) Math.sqrt((double) area);
        return edge * edge == area;
    }

    public int maximalSquare(char[][] matrix) {
        int height = matrix.length;
        int width = matrix[0].length;

        dp = new int[height + 1][width + 1];

        initDp(matrix);

        int maximumSize = Integer.MIN_VALUE;

        for (int r = 1; r <= height; r++) {
            for (int c = 1; c <= width; c++) {

                int maxSquareSize = Math.min(height - r + 1, width - c + 1);

                for (int squareSize = 1; squareSize <= maxSquareSize; squareSize++){
                    int endR = r + squareSize - 1 , endC = c + squareSize - 1;
                    int area = getAreaFromDp(r, c, endR, endC);

                    if (isSquareArea(area) && squareSize * squareSize == area) {
                        maximumSize = Math.max(squareSize, maximumSize);
                    }

                }
            }
        }

        return maximumSize * maximumSize;
    }

    private void initDp(char[][] matrix) {
        int height = matrix.length;
        int width = matrix[0].length;
        for (int r = 1; r <= height; r++) {
            for (int c = 1; c <= width; c++) {
                dp[r][c] = dp[r - 1][c] + dp[r][c - 1] - dp[r - 1][c - 1] + (matrix[r - 1][c - 1] - '0');
            }
        }
    }

    public int getAreaFromDp(int beginR, int beginC, int endR, int endC) {
        return dp[endR][endC] - dp[beginR - 1][endC] - dp[endR][beginC - 1] + dp[beginR - 1][beginC - 1];
    }
}
// @lc code=end

