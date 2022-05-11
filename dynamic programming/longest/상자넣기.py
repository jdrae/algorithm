"""
arr 에서 최대증가수열 찾기
"""
n = int(input())
arr = list(map(int,input().split()))

# bottom up
# 1 6 2 5 가 있으면
# arr[i] = 2 에서 1,2 를 최대로하고
# arr[i] = 5 에서 1,5 와 1,2,5(위에서 계산한) 를 비교해서 1,2,5 선택
mx = 0 
dp = [0] * n
for i in range(n):
    dp[i] = 1
    # 본인 이전의 값에 대해 길이 누적
    for j in range(i):
        if arr[j] < arr[i] and dp[j] + 1 > dp[i]:
            dp[i] = dp[j]+1
    mx = max(mx, dp[i])
print(mx)

# top down
# 시작점이 꼭 인덱스 0 번이 아니다.
# 따라서 모든 위치에서 함수 호출을 해봐야한다.
mx = 0
dp = [0] * n
def func(pos):
    global dp
    ret = dp[pos]
    if ret: return ret
    
    # 본인 다음 값에 대해 최대 길이 탐색
    for i in range(pos+1, n):
        if arr[pos] < arr[i]:
            ret = max(ret, func(i))
    ret += 1  # 본인을 포함한 최대길이
    dp[pos] = ret # 꼭 다시 넣어줘야 메모이제이션 적용
    return ret

for start in range(n):
    mx = max(mx, func(start))
print(mx)