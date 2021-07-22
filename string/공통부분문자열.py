str1, str2 = input(), input()
len1 = len(str1) + 1
len2 = len(str2) + 1
# tip: dp 배열 초기화 (순서 주의)
cache = [[0]*len2 for _ in range(len1)]

ans = 0
for i in range(1, len1):
    for j in range(1, len2):
        if str1[i-1] == str2[j-1]:
            cache[i][j] = cache[i-1][j-1] + 1
            ans = max(ans, cache[i][j])

print(ans)