/*
 * @lc app=leetcode id=91 lang=java
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
    public boolean canPairWithPrevIndex(String s, int index) {
        if (index == 0) {
            return false;
        }

        if (s.charAt(index - 1) == '0') {
            return false;
        }

        int num = (s.charAt(index - 1) - '0') * 10 + (s.charAt(index) - '0');
        return num <= 26;
        
    }

    public int numDecodings(String s) {
        int n = s.length();
        int[] dp = new int[n + 1];

        if (s.charAt(0) == '0') {
            return 0;
        }

        dp[0] = 1;
        for (int i = 1; i<= n; i++) {
            if (s.charAt(i - 1) != '0') {
                dp[i] = dp[i - 1];
            }

            if (canPairWithPrevIndex(s, i - 1)) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
        
    }
}
// @lc code=end

