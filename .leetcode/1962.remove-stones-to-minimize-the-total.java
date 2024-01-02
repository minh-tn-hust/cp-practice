/*
 * @lc app=leetcode id=1962 lang=java
 *
 * [1962] Remove Stones to Minimize the Total
 */

// @lc code=start
import java.util.*;

class Solution {
    PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
    public int minStoneSum(int[] piles, int k) {
        initHeap(piles);

        for (int i = 0; i < k; i++) {
            int maxPile = maxHeap.peek();
            maxHeap.poll();
            maxPile = (maxPile + 1) / 2;
            maxHeap.add(maxPile);
        }

        int minimumAfterKOperation = 0;
        while (!maxHeap.isEmpty()) {
            minimumAfterKOperation += maxHeap.peek();
            maxHeap.poll();
        }

        return minimumAfterKOperation;
        
    }

    void initHeap(int[] piles)  {
        for (int i = 0; i < piles.length; i++) {
            maxHeap.add(piles[i]);
        }
    }
}
// @lc code=end

