/*
 * @lc app=leetcode id=648 lang=java
 *
 * [648] Replace Words
 */

// @lc code=start
import java.util.*;
class TrieNode {
    TrieNode[] child;
    boolean isEndOfWord;
    TrieNode(int base) {
        child = new TrieNode[base];
        isEndOfWord = false;
    }

    public static int charToIndex(char ch) {
        return ch - 'a';
    }

    public static char indexToChar(int index) {
        char ch = (char) (index - 'a');
        return ch;
    }

    public TrieNode getNode(char ch) {
        int index = charToIndex(ch);
        return child[index];
    }

    public void setNode(char ch, TrieNode node) {
        int index = charToIndex(ch);
        child[index] = node;
    }

    public boolean isPresentChar(char ch) {
        TrieNode node = getNode(ch);
        return node != null;
    }
}

class Trie {
    public static final int BASE = 26;
    TrieNode root;
    Trie() {
        root = new TrieNode(BASE);
    }

    public void addRoot(String word) {
        TrieNode currNode = root;
        for (char ch : word.toCharArray()) {
            if (!currNode.isPresentChar(ch)) {
                currNode.setNode(ch, new TrieNode(BASE));
            }
            currNode = currNode.getNode(ch);
        }

        currNode.isEndOfWord = true;
    }

    public String matchingShortestRoot(String successor) {
        TrieNode currNode = root;
        String selectedRoot = "";
        boolean isMatch = true;
        for (char ch : successor.toCharArray()) {
            if (currNode.isPresentChar(ch)) {
                selectedRoot += ch;
                currNode = currNode.getNode(ch);
                if (currNode.isEndOfWord) {
                    return selectedRoot;
                }
            } else {
                isMatch = false;
                break;
            }
        }

        if (isMatch) { 
            return selectedRoot;
        } else {
            return "";
        }

    }

}

class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Trie rootTrie = new Trie();
        for (String root : dictionary) {
            rootTrie.addRoot(root);
        }

        List<String> words = Arrays.asList(sentence.split(" "));
        for (int i = 0; i < words.size(); i++) {
            String matchingRoot = rootTrie.matchingShortestRoot(words.get(i));
            if (matchingRoot.compareTo("") != 0) {
                words.set(i, matchingRoot);
            }
        }
        String replacedSentence = "";
        for (int i = 0; i < words.size(); i++) {
            replacedSentence = replacedSentence.concat(words.get(i));
            if (i != words.size() - 1) {
                replacedSentence += " ";
            }
        }

        return replacedSentence;
    }
}
// @lc code=end

