/*
 * @lc app=leetcode id=1578 lang=java
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution {
    public int minCost(String colors, int[] neededTime) {
        int n = colors.length();
        int maxCostInSequence = neededTime[0];

        int minimumTime = 0;
        for (int i = 0; i < n; i++) {
            minimumTime += neededTime[i];
        }

        for (int i = 0; i < n; i++) {
            maxCostInSequence = Math.max(maxCostInSequence, neededTime[i]);
            if (i == n - 1 || colors.charAt(i) != colors.charAt(i + 1)) {
                minimumTime -= maxCostInSequence;
                maxCostInSequence = 0;
            }        
        }

        return minimumTime;
        
    }
}
// @lc code=end

