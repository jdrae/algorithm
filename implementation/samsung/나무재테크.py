
def spring():
    dead = []
    for y in range(n):
        for x in range(n):
            tree[y][x].sort()
            for idx, age in enumerate(tree[y][x]):
                if arr[y][x] >= age:
                    arr[y][x] -= age
                    tree[y][x][idx] += 1
                else:
                    for a in tree[y][x][idx:]:
                        dead.append((y,x,a))
                    tree[y][x] = tree[y][x][:idx]
                    break
    return dead

def summer(dead):
    for y,x,z in dead:
        arr[y][x] += z//2

def fall():
    for y in range(n):
        for x in range(n):
            for age in tree[y][x]:
                if age % 5 != 0: continue
                for i in range(y-1, y+2):
                    for j in range(x-1, x+2):
                        if i == y and j == x: continue
                        if not (0<=i<n and 0<=j<n): continue
                        tree[i][j].append(1)

def winter():
    for i in range(n):
        for j in range(n):
            arr[i][j] += add[i][j]

if __name__ == "__main__":
    n, m, k = map(int,input().split())
    add = [list(map(int,input().split())) for _ in range(n)]
    arr = [[5]*n for _ in range(n)]
    tree = [[[] for _ in range(n)] for _ in range(n)]

    for _ in range(m):
        y,x,z = map(int,input().split())
        tree[y-1][x-1].append(z)

    while k:
        k -= 1
        dead = spring()
        summer(dead)
        fall()
        winter()
    
    ans = 0
    for y in range(n):
        for x in range(n):
            ans += len(tree[y][x])
    print(ans)