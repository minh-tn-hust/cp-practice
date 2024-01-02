/*
 * @lc app=leetcode id=167 lang=java
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0, right = numbers.length - 1;
        int[] indexs = new int[2];
        while (left <= right) {
            if (numbers[left] + numbers[right] > target) {
                right--;
            } else if (numbers[left] + numbers[right] < target){
                left++;
            } else {
                indexs[0] = left + 1;
                indexs[1] = right + 1;
                return indexs;
            }
        }

        return indexs;
    }
}
// @lc code=end

