from itertools import combinations

n, k = map(int, input().split())
word = []
for _ in range(n):
    word.append(input()[4:-4])

if k < 5: print(0)
elif k == 26: print(n)
else:
    k -= 5
    chars = {'a','n','t','i','c'}
    # tip: 알파벳-숫자 대응 딕셔너리
    alpha = {ky: v 
        for v, ky in enumerate( 
        set( map(chr, range(ord('a'), ord('z')+1)) ) - chars
        )}

    word_bit = []
    for w in word:
        tmp = 0
        for c in set(w) - chars: # tip: 문자열에서 문자 제거
            tmp |= (1 << alpha[c])
        word_bit.append(tmp)
    
    ans = 0
    power_by_2 = (2**i for i in range(21))
    for comb in combinations(power_by_2, k): # tip: 비트 조합
        test = sum(comb)
        cnt = 0
        for bit in word_bit:
            if test & bit == bit:
                cnt += 1

        ans = max(ans, cnt,)

    print(ans)
