def solution(gems):
    answer = []
    n = len(gems)
    # bit masking
    types = set(gems)
    dic = {k:v for v,k in enumerate(types)}
    bit = 0
    for i in range(len(types)):
        bit |= (1<<i)
        
    # two pointer
    s, e, check, mn = 0,0, 0, 100000
    counter = {k:0 for k in set(gems)}
    while s < n and e <= n:
        if check & bit == bit:
            if mn > abs(e-s):
                mn = e-s
                answer = [s+1, e]

            counter[gems[s]] -= 1
            if counter[gems[s]] == 0: check &= ~(1<<dic[gems[s]])
            s += 1
        else:
            if e == n: break
            check |= (1<<dic[gems[e]])
            counter[gems[e]] += 1
            e += 1
    return answer

print(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]), 	[3, 7])
print(solution(['a','b','b','c','a','b','c']), [3,5])
print(solution(['a','a','a']), [1,1])
print(solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"]),[1,5])