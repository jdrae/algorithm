"""
dfs 로 가능한 경우의 수를 탐색하고,
각 경우의 수에 도달할 때마다
보드를 채우고 조건판단.
"""

def func():
    newarr = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            newarr[i][j] = arr[i][j]
    
    def _func(y, x, d):
        while True:
            y, x = y+dy[d], x+dx[d]
            if 0<=y<n and 0<=x<m and newarr[y][x] != 6:
                newarr[y][x] = 9
            else:
                break

    for i, d in enumerate(dirs):
        y, x = cctv[i]
        type = arr[y][x]
        if type == 1:
            _func(y,x,d)
        elif type == 2:
            _func(y,x,d)
            d += 2
            _func(y,x,d)
        elif type == 3:
            _func(y,x,d)
            d = (d+1) % 4
            _func(y,x,d)
        elif type == 4:
            for _ in range(3):
                _func(y,x,d)
                d = (d+1)%4
        else:
            for d in range(4):
                _func(y,x,d)

    return newarr

def dfs(idx):
    global mn
    if idx == len(cctv):
        # arr 수정
        newarr = func()
        # 조건 체크
        cnt = 0
        for i in range(n):
            for j in range(m):
                if newarr[i][j] == 0:
                    cnt += 1
        # 정답 갱신
        mn = min(mn, cnt)
        return

    # 각 idx 별로 전역변수 dirs 에 방향 저장
    y, x = cctv[idx]    
    for d in range(case[arr[y][x]]):
        dirs[idx] = d
        dfs(idx+1)

if __name__ == "__main__":
    case = [0,4,2,4,4,1]
    dy = [-1,0,1,0]
    dx = [0,1,0,-1]

    n, m = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(n)]
    
    cctv = []
    mn = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 0:
                mn += 1
            elif arr[i][j] != 6:
                cctv.append((i,j))

    if cctv:
        dirs = [0] *len(cctv)
        dfs(0)
    print(mn)