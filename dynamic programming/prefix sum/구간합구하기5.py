n,m = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]
cmd = [list(map(int,input().split())) for _ in range(m)]

p_sum = [[0]*(n+1) for _ in range(n+1)]
for i in range(n):
    for j in range(n):
        p_sum[i+1][j+1] = p_sum[i][j+1] + p_sum[i+1][j] - p_sum[i][j] + arr[i][j]

for y1,x1,y2,x2 in cmd:
    print(p_sum[y2][x2] - p_sum[y1-1][x2] - p_sum[y2][x1-1] + p_sum[y1-1][x1-1])