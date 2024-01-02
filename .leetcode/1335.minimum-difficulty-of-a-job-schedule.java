/*
 * @lc app=leetcode id=1335 lang=java
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

// @lc code=start
import java.util.*;

class Solution {

    public int minDifficulty(int[] jobDifficulty, int d) {
        int numJob = jobDifficulty.length;
        if (numJob < d) {
            return -1;
        }
        int[][] dp = new int [numJob + 1][d + 1];

        for (int i = 1; i <= d; i++) {
            dp[0][i] = 100000;
        }

        for (int i = 1; i <= numJob; i++) {
            dp[i][0] = 100000;
        }

        for (int lastJob = 1; lastJob <= numJob; lastJob++) {
            for (int usingDay = 1; usingDay <= d; usingDay++) {

                dp[lastJob][usingDay] = dp[lastJob - 1][usingDay - 1] + jobDifficulty[lastJob - 1];

                int maximumDifficultyOfLastDay = jobDifficulty[lastJob - 1];
                for (int startJobOfLastDay = lastJob - 1; startJobOfLastDay > 0; startJobOfLastDay--) {
                    maximumDifficultyOfLastDay = Math.max(maximumDifficultyOfLastDay, jobDifficulty[startJobOfLastDay - 1]);

                    dp[lastJob][usingDay] = Math.min(
                        dp[lastJob][usingDay],
                        dp[startJobOfLastDay - 1][usingDay - 1] + maximumDifficultyOfLastDay
                    );
                }
            }
        }

        return dp[numJob][d];
    }
}
// @lc code=end

