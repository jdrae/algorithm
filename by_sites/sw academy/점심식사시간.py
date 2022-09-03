from collections import deque

import sys
sys.stdin = open("input.txt", "r")

T = int(input())
for test_case in range(1, T + 1):
    answer = 10000
    # input
    n = int(input())
    arr = [list(map(int, input().split())) for _ in range(n)]

    pawn, stair = [], []
    for i in range(n):
        for j in range(n):
            if arr[i][j] != 0:
                if arr[i][j] == 1:
                    pawn.append((i, j))
                else:
                    stair.append((i, j, arr[i][j]))

    # bit masking
    m = len(pawn)
    bit = (1 << m) - 1
    for case in range(bit + 1):
        move_time = []
        in_stair = [0] * 3

        for pos in range(m):
            i, j = pawn[pos]
            to_move = 1 if case & (1 << pos) else 0
            si, sj, _ = stair[to_move]
            move_time.append((abs(i-si) + abs(j-sj), to_move))
        move_time.sort(key=lambda x: x[0])

        # time
        time, finished = move_time[0][0], 0
        waiting = [deque() for _ in range(2)]
        in_stair = [[0]*3 for _ in range(2)]
        while True:
            # go down
            for num in (0,1):
                for i in range(3):
                    if in_stair[num][i] != 0:
                        in_stair[num][i] -= 1
                        if in_stair[num][i] == 0:
                            finished += 1

            # result
            if finished == m:
                time += 1 # 0 까지 내려오고 또 한칸 내려가야 끝
                answer = min(answer, time)
                break

            # move to stair
            for idx in range(m):
                if move_time[idx][0] == time:
                    num = move_time[idx][1]
                    waiting[num].append(idx)

            # wait or go
            for num in (0,1):
                for i in range(3):
                    if not waiting[num]: continue
                    if in_stair[num][i] != 0: continue
                    in_stair[num][i] = stair[num][2]
                    waiting[num].popleft()

            time += 1


        # break

    # output
    print(f'#{test_case} {answer}')
    # break
