/*
 * @lc app=leetcode id=1233 lang=java
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
import java.util.*;

class Folder implements Comparable<Folder>{
    public static final int HASH_CODE = 1312;
    public Map<String, Folder> subFolders;
    public boolean isEndOfFolder;

    Folder() {
        subFolders = new HashMap<String, Folder>();
        isEndOfFolder = false;
    }

    @Override
    public int hashCode() {
        return HASH_CODE;
    }

    @Override
    public boolean equals(Object o) {
        Folder otherFolder = (Folder) o;
        return compareTo(otherFolder) == 0;
    }

    @Override
    public int compareTo(Folder otherFolder) {
        return (subFolders == otherFolder.subFolders) ? 0 : 1;
    }

    public Folder getFolder(String name) {
        return subFolders.get(name);
    }

    public boolean hasSubFolder(String name) {
        return subFolders.get(name) != null;
    }

    public void setFolder(String name, Folder folder) {
        subFolders.put(name, folder);
    }
}

class FolderTrie {
    Folder root;

    FolderTrie() {
        root = new Folder();
    }

    public boolean addFolderAsParent(List<String> folderPath) {
        Folder currFolder = root;
        if (!hasParentFolder(folderPath)) {
            for (String folderName : folderPath) {
                if (!currFolder.hasSubFolder(folderName)) {
                    currFolder.setFolder(folderName, new Folder());
                }

                currFolder = currFolder.getFolder(folderName);
            }
            currFolder.isEndOfFolder = true;
            return true;
        }
        return false;
    }

    public boolean hasParentFolder(List<String> folderPath) {
        Folder currFolder = root;

        for (String folderName : folderPath) {
            if (currFolder.hasSubFolder(folderName)) {
                currFolder = currFolder.getFolder(folderName);
            } else {
                break;
            }
        }

        if (currFolder.isEndOfFolder == true) {
            return true;
        }

        return false;
    }
}

class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);

        FolderTrie folderTrie = new FolderTrie();

        List<String> res = new ArrayList<>();

        for (int i = 0; i < folder.length; i++) {
            List<String> folderPath = Arrays.asList(folder[i].substring(1).split("/"));
            boolean isParentFolder = folderTrie.addFolderAsParent(folderPath);
            if (isParentFolder) {
                res.add(getFolderAllPath(folderPath));
            }
        }

        return res;
    }

    public String getFolderAllPath(List<String> folderPath) {
        String res = "/";
        for (int i = 0; i < folderPath.size(); i++){
            res = res.concat(folderPath.get(i));
            if (i != folderPath.size() - 1) {
                res += "/";
            }
        }

        return res;
    }
}
// @lc code=end

