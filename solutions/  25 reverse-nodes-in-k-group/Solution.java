/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        // Advance to end of group
        ListNode prev = head;
        for (int i = 0; i < k; i++) {
            // If not enough nodes, return head as-is
            if (prev == null) return head;
            prev = prev.next;
        }
        prev = reverseKGroup(prev, k);

        // Try to reverse k nodes
        for (int i = 0; i < k; i++) {
            ListNode nextNode = head.next;
            head.next = prev;
            prev = head;
            head = nextNode;
        }

        // Return new head - head is at next reversed group
        return prev;
    }
}