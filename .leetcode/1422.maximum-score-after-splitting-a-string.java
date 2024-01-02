/*
 * @lc app=leetcode id=1422 lang=java
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start

class Solution {
    public int maxScore(String s) {
        int numOfZeros = 0;
        int numOfOnes = 0;
        int size = s.length();
        for (int i = 0; i < size; i++) {
            if (s.charAt(i) == '1') {
                numOfOnes++;
            }
        }

        int maximumScore = Integer.MIN_VALUE;
        for (int i = 0; i < size - 1; i++) {
            if (s.charAt(i) == '0') {
                numOfZeros++;
            } else {
                numOfOnes--;
            }

            maximumScore = Math.max(numOfOnes + numOfZeros, maximumScore);
        }

        return maximumScore;
        
    }
}
// @lc code=end

