"""
deepcopy 대신 slicing 사용하기 (100배 빠름)
clone = [row[:] for row in arr]
"""
n = int(input())
arr = [list(map(lambda x: 1 if x=='T' else 0,input())) for _ in range(n)]
clone = [row[:] for row in arr]

def toggle_y(idx):
    for i in range(n):
        arr[idx][i] ^= 1

answer = 401
BIT = (1<<n) - 1
for by in range(BIT):
    # 경우의 수대로 행을 뒤집는다
    for i in range(n):
        if by & (1<<i):
            toggle_y(i)
    
    # 각 열의 t 의 개수에 따라 열을 뒤집을지 말지 결정한다
    # t 가 대다수면 열을 뒤집고, 그렇지 않으면 놔두는 식.
    # 결국 열을 실제로 뒤집을 필요는 없고, 뒤집었다는(혹은 아니라는) 가정하에 개수만 센다
    cnt = 0
    for j in range(n):
        t = 0
        for i in range(n):
            t += arr[i][j]
        cnt += min(t, n-t)
    answer = min(answer, cnt)

    # 원상복구
    arr = [row[:] for row in clone]

print(answer)