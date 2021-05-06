def expand(s, left, right):
    while left >= 0 and right < len(s) and s[left] == s[right]:
        left -= 1
        right += 1
    return s[left + 1 : right]

def solution(s):
    print("INPUT\n", s)
    if(len(s) < 2 or s == s[::-1]):
        return s
    result = ''
    for i in range(len(s) - 1):
        result = max(result, expand(s, i, i+1), expand(s, i,i+2), key=len)
    return result
    

print("OUTPUT\n", solution("bababd"))