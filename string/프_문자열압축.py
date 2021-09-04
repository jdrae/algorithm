def solution(s):
    n = len(s)
    answer = n
    for j in range(1, n//2+1): # 압축 문자열 길이
        cnt = 1
        ans = ''
        i = 0
        while i < n:
            same = True
            if i + j + j <= n:
                for k in range(j):
                    if s[i+k] != s[i+k+j]:
                        same = False
                        break
                if same:
                    cnt += 1
                    i += j
                else:
                    if cnt != 1:
                        ans += str(cnt)
                        cnt = 1
                    ans += s[i:i+j]
                    i += j
            else:
                if cnt != 1:
                    ans += str(cnt)
                    cnt = 1
                ans += s[i]
                i += 1
        answer = min(answer, len(ans))
    return answer

# print(solution("aabbaccc"))
# print(7)
# print(solution("abcabcdede"))
# print(8)
# print(solution("xababcdcdababcdcd"))
# print(17)
print(solution(	"ababcdcdababcdcd"))
print(9)
