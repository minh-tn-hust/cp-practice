/*
 * @lc app=leetcode id=1268 lang=java
 *
 * [1268] Search Suggestions System
 */

// @lc code=start

import java.util.*;




class Solution {

    public int search(String[] products, String matchingWord) {
        int left = 0, right = products.length - 1;
        while (left <= right) {
            int middle = (left + right) >> 1;
            String currentWord = products[middle];
            if (matchingWord.compareTo(currentWord) > 0) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return left;
    }

    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products);

        List<List<String>> suggests = new ArrayList<>();
        String subWord;
        for (int i = 0; i < searchWord.length(); i++) {
            subWord = searchWord.substring(0, i + 1);
            int firstMatchIndex = search(products, subWord);
            List<String> suggestWords = new ArrayList<>();
            for (int j = firstMatchIndex; j < Math.min(firstMatchIndex + 3, products.length); j++) {
                if (subWord.compareTo(products[j].substring(0, Math.min(subWord.length(), products[j].length()))) == 0) {
                    suggestWords.add(products[j]);
                }
            }
            suggests.add(suggestWords);
        }

        return suggests;
    }
}
// @lc code=end

