/*
 * @lc app=leetcode id=2187 lang=java
 *
 * [2187] Minimum Time to Complete Trips
 */

// @lc code=start
class Solution {
    public long totalCompletedTripAtTime(long pointOfTime, int[] time) {
        long totalCompletedTrip = 0;
        for (int tripTime : time) {
            totalCompletedTrip += (pointOfTime / tripTime);
        }

        return totalCompletedTrip;
    }
    public long minimumTime(int[] time, int totalTrips) {

        long maximumTimeOfATrip = time[0];
        for (int tripTime : time) {
            maximumTimeOfATrip = Math.max(maximumTimeOfATrip, tripTime);
        }

        long left = 1, right = totalTrips * maximumTimeOfATrip;

        while (left <= right) {
            long mid = (left + right) >> 1;

            long totalCompletedTrip = totalCompletedTripAtTime(mid, time);
            if (totalCompletedTrip >= totalTrips) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return right + 1;
    }
}
// @lc code=end

