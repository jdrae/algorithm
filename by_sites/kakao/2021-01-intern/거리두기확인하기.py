from collections import deque, defaultdict

n, m = 5, 2
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]


def check(arr):
    people = []
    for y in range(n):
        for x in range(n):
            if arr[y][x] == 'P':
                people.append((y, x))

    for y, x in people:
        visited = [[0] * n for _ in range(n)]
        q = deque([(y, x)])
        visited[y][x] = 1

        is_fine = True
        level = 0
        while q:
            qsize = len(q)
            for _ in range(qsize):
                cy, cx = q.popleft()
                for d in range(4):
                    ny, nx = cy + dy[d], cx + dx[d]
                    if not (0 <= ny < n and 0 <= nx < n) or visited[ny][nx]: continue
                    if arr[ny][nx] == 'X': continue # 파티션이라면
                    visited[ny][nx] = visited[cy][cx] + 1
                    if visited[ny][nx] - 1 <= m and arr[ny][nx] == 'P':
                        return False
                    q.append((ny, nx))
            level += 1
            if level > m:
                break
    return True


def solution(places):
    answer = []

    for arr in places:
        ret = 0
        if check(arr): ret = 1
        answer.append(ret)

    return answer

print(solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]))