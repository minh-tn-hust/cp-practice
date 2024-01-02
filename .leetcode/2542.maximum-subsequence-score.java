/*
 * @lc app=leetcode id=2542 lang=java
 *
 * [2542] Maximum Subsequence Score
 */

// @lc code=start

import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {

    public static final int S1 = 0;
    public static final int S2 = 1;
    public long maxScore(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        int[][] combine = new int[n][2];
        
        for (int i = 0; i < n; i++) {
            combine[i][S1] = nums1[i];
            combine[i][S2] = nums2[i];
        }

        Arrays.sort(combine, (a, b) -> - a[S2] + b[S2]);

        PriorityQueue<Integer> kS1Elements = new PriorityQueue<>();

        long sum = 0;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            sum += combine[i][S1];
            kS1Elements.add(combine[i][S1]);

            if (kS1Elements.size() > k) {
                sum -= kS1Elements.peek();
                kS1Elements.poll();
            }

            if (kS1Elements.size() == k) {
                ans = Math.max(ans, sum * combine[i][S2]);
            }
        }

        return ans;
    }
}
// @lc code=end

