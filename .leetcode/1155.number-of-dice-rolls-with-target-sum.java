/*
 * @lc app=leetcode id=1155 lang=java
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        int[][] dp = new int[n + 1][target + 1];

        for (int sum = 1; sum <= Math.min(k, target); sum++) {
            dp[1][sum] = 1;
        }

        for (int numberOfDice = 2; numberOfDice <= n; numberOfDice++) {
            for (int sum = 1; sum <= target; sum++) {
                for (int pointOfDice = 1; pointOfDice <= k; pointOfDice++) {
                    if (sum - pointOfDice >= 0) {
                        dp[numberOfDice][sum] += dp[numberOfDice - 1][sum - pointOfDice];
                    }
                }
            }
        }

        return dp[n][target];
    }
}
// @lc code=end

