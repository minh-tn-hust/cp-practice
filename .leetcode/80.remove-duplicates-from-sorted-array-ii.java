/*
 * @lc app=leetcode id=80 lang=java
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start


class Solution {

    public static final int MAX_APPEAR_TIME = 2;
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int uniquePointer = 0, duplicatePointer = 0;
        int appearTime = 0;

        for (duplicatePointer = 0; duplicatePointer < n; duplicatePointer++) {
            if (nums[uniquePointer] == nums[duplicatePointer]) {
                appearTime++;
                continue;
            }

            uniquePointer = updateUniqueElement(nums, uniquePointer, appearTime);

            appearTime = 1;
            nums[uniquePointer] = nums[duplicatePointer];
        }

        uniquePointer = updateUniqueElement(nums, uniquePointer, appearTime);

        return uniquePointer;
    }

    public int updateUniqueElement(int[] nums, int uniquePointer, int appearTime) {
        appearTime = Math.min(appearTime, MAX_APPEAR_TIME);

        int element = nums[uniquePointer];

        for (int i = 0; i < appearTime; i++) {
            nums[uniquePointer] = element;
            uniquePointer++;
        }

        return uniquePointer;
    }
}
// @lc code=end

