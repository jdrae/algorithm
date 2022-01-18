# solve again
"""
좌표가 아니더라도 bfs 생각해내기
dp 규칙 꼼꼼히 생각해보기(역으로 생각하기)
"""
from collections import deque

s = int(input())
MAX = 1001

# bfs
visited = [[0]*MAX for _ in range(MAX)] # visited[i][j]: 화면이모티콘개수 i, 클립보드이모티콘개수 j
q = deque([(1,0,0)]) # i, j, 시간 t
visited[1][0] = 1

while q:
    disp, clip, t = q.popleft()
    if disp == s:
        print(t)
        break
    if 0 < disp < MAX:
        # 클립보드에 이모티콘 복사(화면개수 = 클립보드개수)
        if not visited[disp][disp]:
            visited[disp][disp] = 1
            q.append((disp,disp,t+1))
        # 화면이모티콘 삭제
        if not visited[disp-1][clip]:
            visited[disp-1][clip] = 1
            q.append((disp-1,clip,t+1))
    if 0 < clip and disp+clip < MAX:
        # 클립보드의 이모티콘 붙여넣기
        if not visited[disp+clip][clip]:
            visited[disp+clip][clip] = 1
            q.append((disp+clip, clip, t+1))

# dp
dp = list(range(1001)) # 1을 복사해서 계속 붙여넣는 경우
dp[1] = 0
for i in range(2,s+1):
    j = 2
    while i*j < 1001:
        dp[i*j] = min(dp[i*j], dp[i] + j) # i값을 j번 복사하는 경우(i를 만들기 위한 최솟값 + j 번)
        dp[i*j-1] = min(dp[i*j-1], dp[i*j] + 1) # 윗줄의 값에서 하나를 삭제하는 경우(연산 1개 추가)
        j+=1
print(dp[s])