import collections
import re
def solution(s):
    print("INPUT:\n", s)
    # strs = []
    strs : Deque = collections.deque()
    for char in s:
        if char.isalnum(): # 영문자, 숫자 여부 판별
            strs.append(char.lower())

    while len(strs) > 1:
        # if strs.pop(0) != strs.pop():
        if strs.popleft() != strs.pop():
            return False
    return True

def solution1(s):
    print("INPUT:\n", s)
    s = s.lower()
    s = re.sub('[^a-z0-9]', '', s) # 영문자, 숫자만 남김

    return s == s[::-1] # 문자열 뒤집어서 비교

print("OUTPUT:\n", solution1("A man, a plan, a canal: Panama"))
print("OUTPUT:\n", solution1("race a car"))
