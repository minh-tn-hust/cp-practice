/*
 * @lc app=leetcode id=34 lang=java
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
    public int beginIndexSearch(int[] nums, int target) {
        int n = nums.length;
        int left = 0, right = n - 1;
        int beginIndex = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= target) {
                beginIndex = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }

        return (beginIndex != -1 && nums[beginIndex] == target) ? beginIndex : -1;
    }

    public int endIndexSearch(int[] nums, int target) {
        int n = nums.length;
        int left = 0, right = n - 1;
        int endIndex = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] <= target) {
                endIndex = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return (endIndex != -1 && nums[endIndex] == target) ? endIndex : -1;
    }

    public int[] searchRange(int[] nums, int target) {
        int[] indexs = new int[2];

        indexs[0] = beginIndexSearch(nums, target);
        indexs[1] = endIndexSearch(nums, target);

        return indexs;
    }
}
// @lc code=end

