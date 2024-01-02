/*
 * @lc app=leetcode id=1707 lang=java
 *
 * [1707] Maximum XOR With an Element From Array
 */

// @lc code=start
class TrieNode {
    TrieNode[] child;

    public TrieNode(int base) {
        child = new TrieNode[base];
    }

    public TrieNode getNode(int bit) {
        return child[bit];
    }

    public boolean isPresentBit(int bit) {
        return (child[bit] != null);
    }

    public void setNode(int bit, TrieNode newNode) {
        child[bit] = newNode;
    }

}

class BinaryTrie {

    public static final int BASE = 2;
    public static final int MAX_BIT = 30;

    TrieNode root;

    BinaryTrie() {
        root = new TrieNode(BASE);
    }

    public void addNumber(int num) {
        TrieNode currNode = root;
        for (int i = MAX_BIT; i >= 0; i--) {
            int currBit = (num >> i) & 1;

            if (!currNode.isPresentBit(currBit)) {
                currNode.setNode(currBit, new TrieNode(BASE));
            }

            currNode = currNode.getNode(currBit);
        }
    }

    // Try to get the answer's bit = 1
    public int getNumberWithMaxXor(int num, int m) {
        TrieNode currNode = root;
        int res = 0;
        boolean isMBigger = false;
        for (int i = MAX_BIT; i >= 0; i--) {
            int currBit = (num >> i) & 1;
            int mBit = (m >> i) & 1;
            int requireBitToMaximumXor = currBit ^ 1;

            if (!currNode.isPresentBit(requireBitToMaximumXor)) {
                requireBitToMaximumXor = currBit;
            }

            if (mBit < requireBitToMaximumXor && !isMBigger) {
                requireBitToMaximumXor = mBit;
            }
            System.out.println(requireBitToMaximumXor);
            if (currNode.isPresentBit(requireBitToMaximumXor)) {
                if (requireBitToMaximumXor < mBit) {
                    isMBigger = true;
                }
                res += (requireBitToMaximumXor << i);
                currNode = currNode.getNode(requireBitToMaximumXor);
            } else {
                return -1;
            }
        }

        return res;
    }


}
class Solution {
    public static final int X = 0;
    public static final int M = 1;

    public int[] maximizeXor(int[] nums, int[][] queries) {
        BinaryTrie trie = new BinaryTrie();

        int[] answer = new int[queries.length];


        for (int num : nums) {
            trie.addNumber(num);
        }

        int index = 0;
        for (int[] query : queries) {
            int x = query[X];
            int m = query[M];
            
            int maxNumber = trie.getNumberWithMaxXor(x, m);
            System.out.println(maxNumber);
            if (maxNumber == -1) {
                answer[index++] = -1;
            } else {
                answer[index++] = x ^ maxNumber;
            }
        }

        return answer;
        
    }
}
// @lc code=end

