/*
 * @lc app=leetcode id=746 lang=java
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {

    public int minCostClimbingStairs(int[] cost) {
        int topFloor = cost.length;
        int[] dp = new int[topFloor + 1];
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= topFloor; i++) {
            dp[i] = Math.min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[topFloor];
    }
}
// @lc code=end

