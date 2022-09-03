from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head: return None

        cur, prev = head, None
        while left > 1:
            prev = cur
            cur = cur.next
            left, right = left - 1, right -1
        
        con, tail = prev, cur
        while right:
            tmp = cur.next
            cur.next = prev
            prev = cur
            cur = tmp
            right -= 1
        
        if con:
            con.next = prev
        else:
            head = prev
        tail.next = cur
        return head
        

res = Solution().reverseBetween(
    ListNode(1, ListNode(2, ListNode(3, ListNode(4,ListNode(5,None))))),
    2,4
)

while True:
    print(res.val, end=" ")
    res = res.next
    if res == None:
        break
print()