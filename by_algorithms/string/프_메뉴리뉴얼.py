import itertools

def solution(orders, course):
    answer = []
    for i in course:
        dic = {}
        for o in orders:
            if len(o) < i: continue
            # tip: 순열, 조합
            for c in itertools.combinations(o,i):
                # tip: 문자열 내부 문자 정렬
                c = "".join(sorted(list(c)))
                if c in dic:
                    dic[c] += 1
                else:
                    dic[c] = 1
        if not dic: continue
        # tip: dictionary 정렬
        dic = sorted(dic.items(), key=(lambda x:x[1]), reverse=True)
        mx = dic[0][1]
        if mx < 2: break
        for k, v in dic:
            if v == mx: answer.append(''.join(k))
            else: break
    return sorted(answer)

print(solution(["ABCFG", "CA", "CDE", "ACDE", "BCFG", "ACDEH"],[2,3,4]))