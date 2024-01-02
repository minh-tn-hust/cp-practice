/*
 * @lc app=leetcode id=875 lang=java
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
    public boolean canKokoEatAllBanana(int[] piles, int k, int h) {
        long totalEatingHours = 0;
        for (int pile : piles) {
            totalEatingHours += ((pile - 1) / k + 1);
        }

        return (totalEatingHours <= h);
    }

    public int minEatingSpeed(int[] piles, int h) {
        int maximumValueOfK = piles[0];
        for (int pile : piles) {
            maximumValueOfK = Math.max(maximumValueOfK, pile);
        }

        int left = 1, right = maximumValueOfK;
        int suitableK = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;

            if (canKokoEatAllBanana(piles, mid, h)) {
                right = mid - 1;
                suitableK = mid;
            } else {
                left = mid + 1;
            }
        }

        return suitableK;
    }
}
// @lc code=end

