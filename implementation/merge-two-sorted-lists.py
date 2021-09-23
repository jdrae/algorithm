from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        ptr = head
        while l1 and l2:
            if l1.val < l2.val:
                ptr.next = l1
                l1 = l1.next
            else:
                ptr.next = l2
                l2 = l2.next
        ptr.next = l1 or l2
        return head.next

    def recursive(self, l1, l2):
        # tip: 둘 중 하나만 취하기
        if not l1 or not l2:
            return l1 or l2
        if l1.val < l2.val:
            l1.next = self.recursive(l1.next, l2)
        else:
            l2.next = self.recursive(l1, l2.next)
            return l2

# res = Solution().mergeTwoLists(
#     ListNode(1, ListNode(2, ListNode(4, None))),
#     ListNode(1, ListNode(3, ListNode(4, None)))
# )

res = Solution().mergeTwoLists(
    None, None
)

res = Solution().mergeTwoLists(
    None,
    ListNode(1, ListNode(3, ListNode(4, None)))
)

while True:
    print(res.val, end=" ")
    res = res.next
    if res == None:
        break
print()