"""
문제에선 S에서 T를 만들라고 했지만(추가),
반대로 T에서 S를 만드는 걸로(삭제) 바꾸면 훨씬 빠름.
"""

from collections import deque

def add(case):
    global reversed, q
    chr = 'A' if case==1 else 'B'
    if (case == 1 and not reversed) or (case==2 and reversed):
        q.append(chr)
    else:
        q.appendleft(chr)

    if case == 2:
        reversed = True if not reversed else False

def remove(case):
    global reversed, q
    if reversed:
        q.popleft()
    else:
        q.pop()


def backtrack():
    global reversed, q
    if len(q) == len(T):
        res = ''.join(q)
        if reversed:
            res = res[::-1]
        print(res, reversed)
        if res == T:
            return 1
        return 0
    
    add(1)
    if backtrack():
        return 1
    remove(1)

    add(2)
    if backtrack():
        return 1
    remove(2)
    reversed = True if not reversed else False

    return 0


if __name__ =="__main__":
    S, T = input(), input()
    reversed = False
    q = deque(list(T))
    while len(q) != len(S):
        if reversed:
            last = q.popleft()
        else:
            last = q.pop()

        if last == 'B':
            reversed = True if not reversed else False
    
    res = ''.join(q)
    if reversed:
        res = res[::-1]
    if res == S:
        print(1)
    else:
        print(0)
