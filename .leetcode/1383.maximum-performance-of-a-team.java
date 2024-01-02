/*
 * @lc app=leetcode id=1383 lang=java
 *
 * [1383] Maximum Performance of a Team
 */

// @lc code=start

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public static int SPEED = 0;
    public static int EFFICIENCY = 1; 
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        int[][] engineers = new int[n][2];

        for (int i = 0; i < n; i++) {
            engineers[i][SPEED] = speed[i];
            engineers[i][EFFICIENCY] = efficiency[i];
        }

        Arrays.sort(engineers, (a, b) -> b[EFFICIENCY] - a[EFFICIENCY]);

        PriorityQueue<Integer> speedPriority = new PriorityQueue<>();
        int sumSpeed = 0;
        int maxPerformance = 0;
        for (int i = 0; i < n; i++) {
            sumSpeed += engineers[i][SPEED];
            speedPriority.add(engineers[i][SPEED]);

            if (speedPriority.size() > k) {
                sumSpeed -= speedPriority.peek();
                speedPriority.poll();
            }

            if (speedPriority.size() == k) {
                maxPerformance = Math.max(maxPerformance, sumSpeed * engineers[i][EFFICIENCY]);
            }
        }

        return maxPerformance;
    }
}
// @lc code=end

