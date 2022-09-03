from collections import deque

def solution(board):
    answer = 500 * 25 * 25
    n = len(board)
    # 상하좌우
    dx = [0,0,-1,1]
    dy = [-1,1,0,0]
    op = [1,0,3,2]

    # bfs
    # 방향 별 방문 기록 저장
    visited = [[([0] * 4) for _ in range(n)] for __ in range(n)]
    q = deque([])
    q.append((0,0,-1,0))
    
    while q:
        cy, cx, cd, cv = q.popleft() # y, x, 방향, 값
        if answer <= cv: continue
        if cy == n-1 and cx == n-1:
            answer = min(answer, cv)
            continue
        for d in range(4):
            ny, nx = cy+dy[d], cx+dx[d]
            if(ny<0 or ny>=n or nx<0 or nx>=n): continue
            if board[ny][nx] == 0 and (cd == -1 or d != op[cd]):
                nv = cv + 100
                if cd != d and cd != -1: nv += 500 # 방향 다르면 400원 추가
                if not visited[ny][nx][d] or visited[ny][nx][d] > nv:
                    q.append((ny,nx,d,nv))
                    visited[ny][nx][d] = nv
    return answer

# print(solution([[0,0,0],[0,0,0],[0,0,0]]),900)
# print(solution([[0,0,1,0],[0,0,0,0],[0,1,0,1],[1,0,0,0]]),2100)
# print(solution([[0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 0], [0, 0, 1, 0, 0, 0], [1, 0, 0, 1, 0, 1], [0, 1, 0, 0, 0, 1], [0, 0, 0, 0, 0, 0]]),3200)
print(solution([[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]]),3800)