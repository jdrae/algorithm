n = int(input())
words = []
for _ in range(n):
    words.append(input())

wton = {}
for w in words:
    for i in range(len(w)):
        if w[i] in wton:
            wton[w[i]] += pow(10,len(w)-i-1)
        else:
            wton[w[i]] = pow(10,len(w)-i-1)

nums = []
for value in wton.values():
    nums.append(value)
nums.sort(reverse=True)

ans, cnt = 0, 9
for i in nums:
    ans += i*cnt
    cnt -= 1

print(ans)

