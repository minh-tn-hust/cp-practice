/*
 * @lc app=leetcode id=2616 lang=java
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

// @lc code=start
import java.util.*;
class Solution {
    public int countValidPair(int[] nums, int threshHold) {
        int n = nums.length;
        int numberOfValidPair = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= threshHold) {
                numberOfValidPair++;
                i++;
            }        
        }

        return numberOfValidPair;
    }

    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);

        int left = 0, right = 1_000_000_000;
        int optimalThreshHold = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;

            int numberOfValidPair = countValidPair(nums, mid);
            if (numberOfValidPair >= p) {
                right = mid - 1;
                optimalThreshHold = mid;
            } else {
                left = mid + 1;
            }
        }

        return optimalThreshHold;
    }
}
// @lc code=end

