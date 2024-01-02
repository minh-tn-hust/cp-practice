/*
 * @lc app=leetcode id=198 lang=java
 *
 * [198] House Robber
 */

// @lc code=start

import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    public int robThisHouse(int index, int[] nums, PriorityQueue<Integer> maximumRobbing) {
        return maximumRobbing.peek() + nums[index];
    }

    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }

        int size = nums.length;
        int[] dp = new int[size];
        dp[0] = nums[0];
        dp[1] = nums[1];

        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        pq.add(dp[0]);

        for (int i = 2; i < size; i++) {
            dp[i] = Math.max(dp[i - 1], robThisHouse(i, nums, pq));
            pq.add(dp[i - 1]);
        }

        int maximum = Integer.MIN_VALUE;
        for (int i = 0; i < size; i++) {
            System.out.print(dp[i] + " ");
            maximum = Math.max(maximum, dp[i]);
        }

        return maximum;
    }
}
// @lc code=end

