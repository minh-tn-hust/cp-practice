/*
 * @lc app=leetcode id=1011 lang=java
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
    public boolean canShipAllPackagesWithWeight(int weight, int[] weights, int days) {
        int n = weights.length;

        int totalShipingDay = 1;
        int totalWeightPerDay = 0;


        for (int i = 0; i < n; i++) {
            if (weights[i] > weight) {
                return false;
            }
            if (totalWeightPerDay + weights[i] <= weight) {
                totalWeightPerDay += weights[i];
            } else {
                totalWeightPerDay = weights[i];
                totalShipingDay += 1;
            }
        }

        return (totalShipingDay <= days);
    }

    public int shipWithinDays(int[] weights, int days) {

        int totalWeight = 0;
        for (int weight : weights) {
            totalWeight += weight;
        }

        int left = 1, right = totalWeight;
        int validWeight = 0;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (canShipAllPackagesWithWeight(mid, weights, days)) {
                right = mid - 1;
                validWeight = mid;
            } else {
                left = mid + 1;
            }
        }

        return validWeight;
        
    }
}
// @lc code=end

