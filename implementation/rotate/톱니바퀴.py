arr = [input() for _ in range(4)]
k = int(input())
com = [list(map(int, input().split())) for _ in range(k)]

L, R = 6, 2
opp = {-1: 1, 1:-1}
left = [L for _ in range(4)]
right = [R for _ in range(4)]
weight = [1,2,4,8]

for num, org_dir in com:
    rotate = [(num,org_dir)]
    # left
    idx = num - 1
    dir = org_dir
    while idx != 0 and arr[idx][left[idx]] != arr[idx-1][right[idx-1]]:
        rotate.append((idx, opp[dir]))
        idx, dir = idx-1, opp[dir]
    # right
    idx = num - 1
    dir = org_dir
    while idx != 3 and arr[idx][right[idx]] != arr[idx+1][left[idx+1]]:
        rotate.append((idx+2, opp[dir]))
        idx, dir = idx+1, opp[dir]
    for n, d in rotate:
        idx = n - 1
        left[idx] = (left[idx] + opp[d] + 8) % 8
        right[idx] = (right[idx] + opp[d] + 8) % 8
ans = 0
for idx, r in enumerate(right):
    zero = (r - R + 8) % 8
    ans += weight[idx] * int(arr[idx][zero])
print(ans)

"""
10101110
10010011
01001110
10000100
4
1 1
2 -1
2 1
2 -1
"""