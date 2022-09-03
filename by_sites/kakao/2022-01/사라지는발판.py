"""
basecase 는 두가지 경우의 패배
이길 가능성이 있다면 가장 빠르게 끝나는 path 를 선택한다, path 자체는 필요없으니 count 갱신.
질수밖에 없다면 가장 오래 걸리는 것을 선택한다. 마찬가지로 최대 count 갱신.
이길 가능성이 하나라도 있으면 그것을 선택한다. 하지만 질 수밖에 없다면 최대값을 선택한다.
따라서 a 에서 최솟값을 선택했더라도 b 가 최댓값을 선택하므로 최적의 플레이가 된다.
또한 a 가 질 경우 더 오래 게임을 할 수 있더라도 a 는 최솟값을 선택한다.
"""

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]


def solution(board, aloc, bloc):
    n, m = len(board), len(board[0])

    # user 의 좌표 y,x 가 움직일 차례, user^1 는 p q 에 있다.
    # 반환 값: 이길 수 있는지(bool), 남은 이동횟수(int)
    path = []
    def dfs(user, y, x, p, q):
        username = 'b' if user else 'a'
        # basecase: 상대가 움직여서 내가 진 경우
        if board[y][x] == 0:
            # print(username, len(path), path)
            return False, 0
        # basecase: 움직일 수 없을 경우
        moved = False
        for d in range(4):
            ny, nx = y + dy[d], x + dx[d]
            if not (0 <= ny < n and 0 <= nx < m) or board[ny][nx] == 0: continue
            moved = True
        if not moved:
            # print(username, len(path), path)
            return False, 0

        # 다음
        winner, mn, mx = False, float('inf'), float('-inf')
        for d in range(4):
            ny, nx = y + dy[d], x + dx[d]
            if not (0 <= ny < n and 0 <= nx < m) or board[ny][nx] == 0: continue
            board[y][x] = 0
            path.append((username, ny,nx))
            pq_win, move_cnt = dfs(user ^ 1, p, q, ny, nx) # 상대의 이동횟수
            board[y][x] = 1
            path.pop()

            move_cnt += 1 # 내가 이동한 횟수 1 더함
            if not pq_win: # 내가 이길경우(상대가 질경우) 최소한으로 움직임
                winner = True
                mn = min(mn, move_cnt)
            else: # 내가 질경우 최대한으로 움직임
                mx = max(mx, move_cnt)

        ret = mn if winner else mx # 한번이라도 이길수 있으면 최소한의 움직임 선택
        return winner, ret

    _, answer = dfs(0, aloc[0], aloc[1], bloc[0], bloc[1])
    return answer


print(solution([[1, 1, 1], [1, 1, 1], [1, 1, 1]], [1, 0], [1, 2]), 5)
print("===")
print(solution([[1, 1, 1], [1, 0, 1], [1, 1, 1]], [1, 0], [1, 2]), 4)
