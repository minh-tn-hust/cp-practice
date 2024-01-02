/*
 * @lc app=leetcode id=15 lang=java
 *
 * [15] 3Sum
 */

// @lc code=start
import java.util.*;

class Solution {
    public List<List<Integer>> findPairHasTargetSum(int target, int[] nums, int begin, int end) {
        List<List<Integer>> pairs = new ArrayList<>();


        int left = begin, right = end;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                left++;
            } else if (nums[left] + nums[right] > target) {
                right--;
            } else {
                List<Integer> pair = new ArrayList<>();
                pair.add(nums[left]);
                pair.add(nums[right]);
                pairs.add(pair);

                while (left + 1 < right && nums[left] == nums[left + 1]) {
                    left++;
                }

                while (right - 1 > left && nums[right] == nums[right - 1]) {
                    right--;
                }
                right--;
                left++;
            }
        }

        return pairs;
    }

    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;

        Arrays.sort(nums);

        List<List<Integer>> triplets = new ArrayList<>();

        int target = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            if (target != - nums[i]) {
                target = -nums[i];
                List<List<Integer>> pairsHasSumEqualTarget = findPairHasTargetSum(target, nums, i + 1, n - 1);
                for (List<Integer> pair : pairsHasSumEqualTarget) {
                    pair.add(nums[i]);
                    triplets.add(pair);
                }

            }
        }
        return triplets;
    }
}
// @lc code=end

