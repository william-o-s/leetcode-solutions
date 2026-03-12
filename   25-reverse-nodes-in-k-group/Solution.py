# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        '''Given a head, returns the correct head of the reversed group.

        Recursive logic: calling reverseKGroup on head is equivalent to calling
        it on k-th node onwards'''

        # Advance to next group
        prev = head
        for _ in range(k):
            if prev is None:
                return head
            prev = prev.next

        # Reverse the next group
        prev = self.reverseKGroup(prev, k)

        # Reverse the current group
        for _ in range(k):
            nextNode = head.next
            head.next = prev
            prev = head
            head = nextNode

        return prev
