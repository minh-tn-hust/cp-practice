/*
 * @lc app=leetcode id=33 lang=java
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
    public int findingPivotIndex(int[] nums) {
        if (nums.length == 1) {
            return 0;
        }
        int low = 1, high = nums.length - 1, pivot = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[0]) {
                pivot = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return pivot;
    }

    public int search(int[] nums, int target) {
        int pivotIndex = findingPivotIndex(nums);

        int size = nums.length;
        int low = pivotIndex, high = pivotIndex + nums.length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid % size] == target) {
                return mid % size;
            } else if (nums[mid % size] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
}
// @lc code=end

