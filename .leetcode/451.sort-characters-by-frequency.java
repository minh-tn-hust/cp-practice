/*
 * @lc app=leetcode id=451 lang=java
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
import java.util.*;

class Solution {
    public static final int CHAR = 0;
    public static final int FREQ = 1;
    public static final int CHARACTER_SIZE = 255;

    public String frequencySort(String s) {
        int[][] counting = new int[CHARACTER_SIZE][2];
        for (char ch : s.toCharArray()) {
            int index = ch;
            counting[index][CHAR] = ch;
            counting[index][FREQ] += 1;
        }

        Queue<int[]> pq = new PriorityQueue<>((a, b) -> - a[FREQ] + b[FREQ]);
        for (int i = 0; i < CHARACTER_SIZE; i++) {
            if (counting[i][FREQ] != 0) {
                pq.add(counting[i]);
            }
        }

        String res = "";
        while (!pq.isEmpty()) {
            int[] charAndFreq = pq.peek();
            pq.poll();
            char ch = (char) charAndFreq[CHAR];
            int freq = charAndFreq[FREQ];

            for (int i = 0; i < freq; i++) {
                res += ch;
            }
        }


        return res;
    }
}
// @lc code=end

