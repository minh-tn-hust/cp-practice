/*
 * @lc app=leetcode id=2932 lang=java
 *
 * [2932] Maximum Strong Pair XOR I
 */

// @lc code=start
class Solution {
    public int maximumStrongPairXor(int[] nums) {
        int n = nums.length;
        int maximumXor = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isStrongPair(nums[i], nums[j])) {
                    maximumXor = Math.max(maximumXor, nums[i] ^ nums[j]);
                }
            }
        }

        if (maximumXor == Integer.MIN_VALUE) {
            return 0;
        }

        return maximumXor;
    }

    public boolean isStrongPair(int x, int y) {
        return Math.abs(x - y) <= Math.min(x, y);
    }
}
// @lc code=end

