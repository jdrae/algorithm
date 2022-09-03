from collections import deque
import copy

# input
n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))

# solve
"""
특정방향으로 arr 를 기울이면, 해당 행 또는 열의 숫자들이 모여짐.
즉, 빈칸을 제외한 arr 의 숫자들을 q 에 모은 형태.
이후 q 에서 겹쳐지는 부분을 합치고 다시 arr 에 넣으면 된다.
"""
def move(d): # 0왼, 1오, 2위, 3아래
    global n, arr
    q = deque([])
    if d == 0 : # 왼
        for i in range(n):
            for j in range(n):
                if arr[i][j] != 0:
                    q.append(arr[i][j])
                    arr[i][j] = 0
            pos = 0
            while q:
                n1 = q.popleft()
                if not q:
                    arr[i][pos] = n1
                    break
                if n1 == q[0]:
                    n2 = q.popleft()
                    arr[i][pos] = n1 + n2
                else:
                    arr[i][pos] = n1
                pos += 1
    elif d == 1: # 오
        for i in range(n):
            for j in range(n):
                if arr[i][j] != 0:
                    q.append(arr[i][j])
                    arr[i][j] = 0
            pos = n-1
            while q:
                n1 = q.pop()
                if not q:
                    arr[i][pos] = n1
                    break
                if n1 == q[-1]:
                    n2 = q.pop()
                    arr[i][pos] = n1+n2
                else:
                    arr[i][pos] = n1
                pos -= 1
    elif d == 2: # 위
        for j in range(n):
            for i in range(n):
                if arr[i][j] != 0:
                    q.append(arr[i][j])
                    arr[i][j] = 0
            pos = 0
            while q:
                n1 = q.popleft()
                if not q:
                    arr[pos][j] = n1
                    break
                if n1 == q[0]:
                    n2 = q.popleft()
                    arr[pos][j] = n1+n2
                else: 
                    arr[pos][j] = n1
                pos += 1
    else: # 아래
        for j in range(n):
            for i in range(n):
                if arr[i][j] != 0:
                    q.append(arr[i][j])
                    arr[i][j] = 0
            pos = n-1
            while q:
                n1 = q.pop()
                if not q:
                    arr[pos][j] = n1
                    break
                if n1 == q[-1]:
                    n2 = q.pop()
                    arr[pos][j] = n1+n2
                else: 
                    arr[pos][j] = n1
                pos -= 1
 
# tip: 일정 횟수만큼 dfs + backtracking
def dfs(cnt):
    global res, arr
    if cnt == 5:
        for i in range(n):
            for j in range(n):
                res = max(res, arr[i][j])
        return

    # tip: 깊은 복사 for backtracking
    cpy = copy.deepcopy(arr)
    
    for d in range(4):
        move(d)
        dfs(cnt+1)
        arr = copy.deepcopy(cpy)

# result
res = 0
dfs(0)
print(res)

