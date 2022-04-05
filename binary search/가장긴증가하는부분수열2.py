"""
1) 우선 정답 리스트의 마지막 값보다 크다면 값을 추가한다.
2) 값이 작다면, 해당 값을 정답리스트의 lower_bound 인덱스에 추가한다.
즉 기존 값이 더 작은 값으로 변경되고, 1)에서 다음 값을 더 추가할 수 있게 된다.
마지막 정답 리스트의 길이가 원하는 정답이다.
"""

from bisect import bisect_left

n = int(input())
arr = list(map(int,input().split()))
ans = [0]

for num in arr:
    if ans[-1] < num:
        ans.append(num)
    else:
        pos = bisect_left(ans, num)
        ans[pos] = num

print(len(ans) - 1)