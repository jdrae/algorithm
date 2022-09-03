import heapq

n = int(input())
arr = []
for _ in range(n):
    heapq.heappush(arr, int(input()))

ans = 0
while arr:
    tmp = heapq.heappop(arr)
    if arr:
        tmp += heapq.heappop(arr)
        ans += tmp
    else:
        break
    heapq.heappush(arr, tmp)
print(ans)