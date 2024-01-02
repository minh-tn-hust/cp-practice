/*
 * @lc app=leetcode id=142 lang=java
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = NO_CYCLE;
 *     }
 * }
 */

public class Solution {
    public static final ListNode NO_CYCLE = null;
    public boolean hasNext(ListNode node) {
        return node.next != NO_CYCLE;
    }

    public ListNode findFisrtMetNode(ListNode fast, ListNode slow) {

        while (hasNext(fast) && hasNext(fast.next)) {
            slow= slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                return slow;
            }
        }

        return NO_CYCLE;
    }

    public ListNode findStartCycleNode(ListNode fast, ListNode slow) {
        if (fast == slow){
            return fast;
        }

        while (hasNext(fast)) {
            slow= slow.next;
            fast = fast.next;

            if (slow == fast) {
                return slow;
            }
        }

        return NO_CYCLE;
    }

    public ListNode detectCycle(ListNode head) {
        if (head == NO_CYCLE) {
            return NO_CYCLE;
        }

        ListNode firstMetNode = findFisrtMetNode(head, head);

        if (firstMetNode == NO_CYCLE) {
            return NO_CYCLE;
        }

        ListNode startCycleNode = findStartCycleNode(firstMetNode, head);

        return startCycleNode;
        
    }
}
// @lc code=end

