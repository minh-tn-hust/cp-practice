/*
 * @lc app=leetcode id=211 lang=java
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
import java.util.*;

class TrieNode {
    TrieNode[] children;
    public boolean isEndOfWord;

    public TrieNode() {
        children = new TrieNode[26];
    }

    public static int getCharIndex(char ch) {
        return ch - 'a';
    }

    public TrieNode getNode(char ch) {
        int index = getCharIndex(ch);
        return children[index];
    }

    public List<TrieNode> findNode(char ch) {
        List<TrieNode> compatibleNodes = new ArrayList<>();
        if (ch == '.') {
            for (TrieNode node : children) {
                if (node != null) {
                    compatibleNodes.add(node);
                }
            }
        } else {
            int index = getCharIndex(ch);
            compatibleNodes.add(children[index]);
        }

        return compatibleNodes;
    }

    public void addNode(char ch, TrieNode nextNode) {
    }

    public void setEndOfWord() {
        isEndOfWord = true;
    }
}

class WordDictionary {
    TrieNode root;

    public WordDictionary() {
        root = new TrieNode();
    }
    
    public void addWord(String word) {
        TrieNode currNode = root;
        for (char ch : word.toCharArray()) {
            TrieNode nextNode = currNode.getNode(ch);
            if (nextNode == null) {
                nextNode = new TrieNode();
                currNode.addNode(ch, nextNode);
            }

            currNode = nextNode;
        }
        currNode.setEndOfWord();
    }
    
    public boolean search(String word) {
        return search(word, 0, root);
    }

    public boolean search(String word, int index, TrieNode root) {
        if (index == word.length()) {
            if (root.isEndOfWord) {
                return true;
            }
            return false;
        }

        List<TrieNode> nextNodes = root.findNode(word.charAt(index));
        boolean isMatch = true;
        for (TrieNode node : nextNodes) {
            isMatch &= search(word, index + 1, node);
        }

        return isMatch;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
// @lc code=end

