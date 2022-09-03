"""
조합 풀이.
이게 더 빠름. 왜?? 0~3ms
"""
from itertools import combinations
def solution(n, info):
    answer = []
    m = 11
    arr = [ap+1 for ap in info] # 10-i 점을 따기위해 쏴야할 최솟값
    mx = 0
    for k in range(1,n+1):
        for comb in combinations(range(m),k):
            total_n = 0
            for c in comb:
                total_n += arr[c]
            if total_n > n: continue
            a_score, b_score = 0, 0
            for i in range(m):
                if i in comb: a_score += 10-i
                elif info[i]: b_score += 10-i
            if b_score >= a_score: continue
            if mx <= (a_score-b_score):
                mx = a_score-b_score
                res = [0] * m
                for c in comb: res[c] = arr[c]
                answer = res

    if not answer: return [-1]
    total_n = n
    for a in answer:
        total_n -= a
    answer[-1] = total_n
    return answer


"""
비트마스킹 풀이. 5ms
"""
BIT = 2**11 - 1
INF = float('-inf')

def calculate(n, info, state):
    a_score, b_score = 0,0
    diff, lst = 0, []
    for i in range(11):
        if state & (1<<i) == 0:
            lst.append(0)
            if info[i]: a_score += 10-i
        else:
            lst.append(info[i] + 1)
            b_score += 10-i
            n -= info[i] + 1
    if n < 0 or a_score >= b_score:
        return INF, [-1]
    if n > 0:
        lst[-1] += n
    diff = b_score - a_score
    return diff, lst

def solution(n, info):
    answer = [-1]

    mx = INF
    for state in range(BIT):
        diff, lst = calculate(n, info, state)
        if mx <= diff:
            mx = diff
            answer = lst
    return answer

print(solution(10, [0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3]))