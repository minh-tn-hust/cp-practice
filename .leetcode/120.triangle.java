/*
 * @lc app=leetcode id=120 lang=java
 *
 * [120] Triangle
 */

// @lc code=start

import java.util.*;

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int height = triangle.size();

        int[][] dp = new int[height + 1][height + 1];

        for (int level = height - 1; level >= 0; level--) {
            for (int j = 0; j <= level; j++) {
                dp[level][j] = triangle.get(level).get(j) + Math.min(dp[level + 1][j], dp[level + 1][j + 1]);
            }
        }

        return dp[0][0];
        
    }
}
// @lc code=end

