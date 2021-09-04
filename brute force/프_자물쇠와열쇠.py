def solution(key, lock):
    answer = False
    n,m = len(lock), len(key)

    # make board
    padd = [[0]*3*n for _ in range(3*n)]
    for i in range(n):
        for j in range(n):
            padd[n+i][n+j] = lock[i][j]

    # rotate
    for _ in range(4):
        key = list(map(list, (zip(*key[::-1]))))
        # masking
        for di in range(1,3*n):
            for dj in range(1,3*n):
                res = True
                # plus
                for i in range(m):
                    for j in range(m):
                        if 0<=di+i<3*n and 0<=dj+j<3*n:
                            padd[di+i][dj+j] += key[i][j]

                # check
                for i in range(n):
                    for j in range(n):
                        if padd[n+i][n+j] != 1:
                            res = False
                if res: return True

                # minus
                for i in range(m):
                    for j in range(m):
                        if 0<=di+i<3*n and 0<=dj+j<3*n:
                            padd[di+i][dj+j] -= key[i][j]
    return answer

# print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]	))
# print(True)

print(solution([[0, 0], [1, 0]], [[1, 0, 0], [1, 1, 1], [1, 1, 1]]	))
print(False)