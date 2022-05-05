from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.curr = None
        self.deleted = deque()

    def print_list(self):
        node = self.head
        print("current:",self.curr.data)
        while node is not None:
            print(node.data, "->", end=" ")
            node = node.next
        print()

    def print_list_rev(self):
        node = self.tail
        while node is not None:
            print(node.data, "->", end=" ")
            node = node.prev
        print()

    def make_n_list(self, n, curr):
        # assert n >= 0 and curr >= 0
        node = Node(0)
        self.head = node
        prev = node
        for i in range(1,n):
            node = Node(i)
            prev.next = node
            node.prev = prev
            prev = node
            if i == n-1:
                self.tail = node
            if i == curr:
                self.curr = node

    def delete_current(self):
        self.deleted.append(self.curr)
        left = self.curr.prev
        right = self.curr.next

        if left is None:
            if right is None:
                self.head = None
                self.tail = None
                self.curr = None
            else:
                right.prev = None
                self.head = right
                self.curr = right
        else:
            if right is None:
                left.next = None
                self.tail = left
                self.curr = left
            else:
                left.next = right
                right.prev = left
                self.curr = right

    def undo_recent(self):
        node = self.deleted.pop() # have prev and next
        left = node.prev
        right = node.next

        if left is None:
            if right is None:
                self.head = node
                self.tail = node
                self.curr = node
            else:
                right.prev = node
                self.head = node
        else:
            if right is None:
                left.next = node
                self.tail = node
            else:
                left.next = node
                right.prev = node

    def down(self,x):
        cnt = 0
        node = self.curr
        while node is not None:
            self.curr = node
            node = node.next
            if cnt == x: break
            cnt += 1

    def up(self,x):
        cnt = 0
        node = self.curr
        while node is not None:
            self.curr = node
            node = node.prev
            if cnt == x: break
            cnt += 1

def solution(n, k, cmd):
    answer = ['X']*n
    lkl = LinkedList()
    lkl.make_n_list(n,k)
    for s in cmd:
        # lkl.print_list()
        # print(s)
        c = s[0]
        if c == "D":
            num = int(s[2:])
            lkl.down(num)
        elif c == "U":
            num = int(s[2:])
            lkl.up(num)
        elif c=="C":
            lkl.delete_current()
        elif c == "Z":
            lkl.undo_recent()
    node = lkl.head
    while node is not None:
        answer[node.data] = 'O'
        node = node.next
    answer = ''.join(answer)
    return answer