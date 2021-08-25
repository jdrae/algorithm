from collections import defaultdict
from itertools import combinations
from bisect import bisect_left

def solution(info, query):
    answer = []
    # prep
    dic = defaultdict(list)
    for inf in info:
        ninf = inf.split()
        for k in range(1,5):
            for comb in combinations(ninf[:-1],k):
                case = ''
                for kw in ninf[:-1]:
                    if kw in comb: case += kw
                    else: case += '-'
                dic[case].append(int(ninf[-1]))
        dic["----"].append(int(ninf[-1]))

    for k in dic.keys():
        dic[k].sort()

    # solve
    for q in query:
        nq = q.split()
        sc = int(nq[-1])
        cand = dic[''.join(nq[::2])]
        # tip: 이진탐색 경계값 위치 찾기 binary serach lower bound
        # https://velog.io/@himinhee/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Lower-bound-Upper-bound-python
        r = bisect_left(cand, sc, lo=0, hi=len(cand))
        # l, r = 0, len(cand)
        # while l < r:
        #     mid = (l+r) // 2
        #     if cand[mid] < sc:
        #         l = mid + 1
        #     else:
        #         r = mid
        answer.append(len(cand) - r)
    return answer

print(solution(
    ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"],
    ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]
))
print(solution(
    ["cpp backend junior pizza 150"],
    ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]
))