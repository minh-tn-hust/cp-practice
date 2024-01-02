/*
 * @lc app=leetcode id=1482 lang=java
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
class Solution {
    public boolean canMakeMBouquetsWithKFlowers(int[] bloomDay, int waitingTime, int m, int k) {
        int n = bloomDay.length;
        boolean[] isBloom = new boolean[n];

        for (int i = 0; i < n; i++) {
            isBloom[i] = (bloomDay[i] <= waitingTime);
        }

        int numberOfBouquets = 0;
        int numberOfFlower = 0;
        for (int i = 0; i < n; i++) {
            if (isBloom[i]) {
                numberOfFlower++;
                if (numberOfFlower == k) {
                    numberOfBouquets++;
                    numberOfFlower = 0;
                }
            } else {
                numberOfFlower = 0;
            }
        }

        return numberOfBouquets >= m;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        int maximumWaitingTime = bloomDay[0];
        for (int i = 0; i < n; i++) {
            maximumWaitingTime = Math.max(maximumWaitingTime, bloomDay[i]);
        }

        int left = 1, right = maximumWaitingTime;
        int minimumWaitingTime = Integer.MIN_VALUE;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canMakeMBouquetsWithKFlowers(bloomDay, mid, m, k)) {
                minimumWaitingTime = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }

        }

        return (minimumWaitingTime == Integer.MIN_VALUE) ? -1 : minimumWaitingTime;
    }
}
// @lc code=end

