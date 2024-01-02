/*
 * @lc app=leetcode id=973 lang=java
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
import java.util.*;

class Solution {
    PriorityQueue<int[]> priorityPoints = new PriorityQueue<>((a, b) -> {
        long aDistance = (a[X] * a[X] + a[Y] * a[Y]);
        long bDistance = (b[X] * b[X] + b[Y] * b[Y]);
        if (aDistance == bDistance) {
            return 0;
        }

        long delta = (aDistance - bDistance) / Math.abs(aDistance - bDistance);

        return (int) delta;
    });
    public static final int X = 0;
    public static final int Y = 1;
    public int[][] kClosest(int[][] points, int k) {
        for (int[] point : points) {
            priorityPoints.add(point);
        }

        int[][] kClosestPoints  = new int[k][2];
        for (int i = 0; i < k; i++) {
            kClosestPoints[i] = priorityPoints.peek();
            priorityPoints.poll();
        }

        return kClosestPoints;
    }
}
// @lc code=end

