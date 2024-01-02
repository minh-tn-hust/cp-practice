/*
 * @lc app=leetcode id=421 lang=java
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
class TrieNode {
    TrieNode[] child;
    TrieNode() {
        child = new TrieNode[2];
    }

    public boolean isPresentBit(int b) {
        if (child[b] == null) {
            return false;
        }

        return true;
    }

    public TrieNode getNode(int b) {
        return child[b];
    }

    public void setNode(int b, TrieNode node) {
        child[b] = node;
    }
}

class BinaryTrie {
    TrieNode root;
    public static final int MAX_BIT = 30;

    public BinaryTrie() {
        root = new TrieNode();
    }

    public void addNumber(int num) {
        TrieNode currNode = root;
        for (int i = MAX_BIT; i >= 0; i--) {
            int currBit = (num >> i) & 1;
            if (!currNode.isPresentBit(currBit)) {
                currNode.setNode(currBit, new TrieNode());
            }

            currNode = currNode.getNode(currBit);
        }
    }

    public int coresponseNumberToMaxXor(int num) {
        TrieNode currNode = root;
        int coresponNumber = 0;
        for (int i = MAX_BIT; i >= 0; i--) {
            int currBit = (num >> i) & 1;

            int requiredBit = currBit ^ 1;

            if (!currNode.isPresentBit(requiredBit)) {
                requiredBit = currBit;
            } 

            currNode = currNode.getNode(requiredBit);
            coresponNumber += (requiredBit << i);
        }

        return coresponNumber;
    }
}

class Solution {
    public int findMaximumXOR(int[] nums) {
        BinaryTrie trie = new BinaryTrie();

        for (int i = 0; i < nums.length; i++) {
            trie.addNumber(nums[i]);
        }



        int max = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int coresponseNum = trie.coresponseNumberToMaxXor(nums[i]);
        }

        return max;
    }
}
// @lc code=end

