/*
 * @lc app=leetcode id=740 lang=java
 *
 * [740] Delete and Earn
 */

// @lc code=start

import java.util.*;

class Solution {
    public static final int VALUE = 0;
    public static final int FREQ = 1;

    public int[][] combineInput(int nums[]) {
        Map<Integer, Integer> combine = new TreeMap<>();

        int size = nums.length;
        for (int i = 0; i < size; i++) {
            if (combine.get(nums[i]) == null) {
                combine.put(nums[i], 1);
            } else {
                int currentValue = combine.get(nums[i]);
                combine.put(nums[i], currentValue + 1);
            }
        }

        int[][] combineArray = new int[combine.size()][2];

        int index = 0;
        for (Map.Entry<Integer, Integer> pair : combine.entrySet()) {
            int key = pair.getKey();
            int value = pair.getValue();
            combineArray[index][VALUE] = key;
            combineArray[index][FREQ] = value;
            index++;
        }

        return combineArray;
    }


    public int deleteAndEarn(int[] nums) {
        int[][] numsAndFreq = combineInput(nums);

        int size = numsAndFreq.length;
        int[] dp = new int[size + 1];

        dp[0] = 0;
        dp[1] = numsAndFreq[0][VALUE] * numsAndFreq[0][FREQ];

        for (int i = 2; i <= size; i++) {
            System.out.println(dp[i - 1] + " " + dp[i - 2]);
            dp[i] = dp[i - 2] + numsAndFreq[i - 1][VALUE] * numsAndFreq[i - 1][FREQ];
            if (numsAndFreq[i - 1][VALUE] - numsAndFreq[i - 2][VALUE] == 1) {
                dp[i] = Math.max(dp[i], dp[i - 1]);
            } else {
                dp[i] = Math.max(dp[i], dp[i - 1] + numsAndFreq[i - 1][VALUE] * numsAndFreq[i - 1][FREQ]);
            }
        }

        return dp[size];
    }
}
// @lc code=end