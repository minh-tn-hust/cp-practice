/*
 * @lc app=leetcode id=2610 lang=java
 *
 * [2610] Convert an Array Into a 2D Array With Conditions
 */

// @lc code=start
import java.util.*;
class Solution {

    public List<List<Integer>> findMatrix(int[] nums) {

        Map<Integer, Integer> numberCounter = countNumber(nums);

        List<List<Integer>> resultingArray = new ArrayList<>();
        for (Map.Entry<Integer, Integer> element : numberCounter.entrySet()) {
            int num = element.getKey();
            int count = element.getValue();

            for (int i = 0; i < count; i++) {
                if (resultingArray.size() < i + 1) {
                    resultingArray.add(new ArrayList<>());
                }
                resultingArray.get(i).add(num);
            }

        }

        return resultingArray;
    }

    public Map<Integer, Integer> countNumber(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> numberCounter = new HashMap<>();
        for (int i = 0; i < n; i++) {
            Integer counter = numberCounter.get(nums[i]);
            if (counter == null) {
                numberCounter.put(nums[i], 1);
            } else {
                numberCounter.put(nums[i], counter + 1);
            }
        }
        return numberCounter;
    }
}
// @lc code=end

