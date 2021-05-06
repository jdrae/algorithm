def solution(s):
    print("INPUT\n", s)
    left, right = 0, len(s) - 1
    while left < right:
        s[left], s[right] = s[right], s[left]
        left += 1
        right -= 1
    return s

def solution1(s):
    print("INPUT\n", s)
    # s.reverse()
    # s = s[::-1]
    s[:] = s[::-1]
    return s

print("OUTPUT\n", solution1(["h","e","l","l","o"]))