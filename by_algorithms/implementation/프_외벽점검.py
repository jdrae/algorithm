from itertools import permutations

def solution(n, weak, dist):
    answer = 9
    m, k = len(weak), len(dist)
    weak = weak + [n+w for w in weak]
    dist.sort(reverse=True)

    for s in range(m):
        for per in permutations(dist, k):
            idx, cnt = 0, 1
            cover = weak[s] + per[idx]
            for i in range(s, s+m):
                if cover < weak[i]:
                    cnt += 1
                    if cnt > k: break
                    idx += 1
                    cover = per[idx] + weak[i]
            answer = min(answer, cnt)
    if answer > k: answer = -1
    return answer

print(solution(12, 	[1, 5, 6, 10], 	[1, 2, 3, 4] ),	2)
print(solution(12, 	[1, 3, 4, 9, 10], 	[3, 5, 7]), 	1)
print(solution(12, [0,10], [1,2]),1)
print(solution(200, [0,100], [1,1]), 2)
print(solution(200, [0, 10, 50, 80, 120, 160],  [1, 10, 5, 40, 30]), 3)
print(solution(3, [0,2], [1]), -1)