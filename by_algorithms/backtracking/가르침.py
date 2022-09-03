alph = [0] * 26
word = []
mx = 0

def backtracking(a, cnt):
    global alph, mx
    if cnt == 0:
        sum = 0
        for w in word:
            check = True
            for c in w:
                if alph[ord(c)-ord('a')] == 0:
                    check = False
                    break
            if check: sum += 1
        mx = max(sum, mx)
        return

    for i in range(26):
        if alph[i] == 0:
            alph[i] = 1
            backtracking(chr(i + ord('a')), cnt-1)
            alph[i] = 0
        
if __name__ == "__main__":
    n, k = map(int, input().split())
    for _ in range(n):
        word.append(input()[4:-4])
    if k < 5:
        print(0)
    elif k == 26:
        print(n)
    else: 
        for c in "antic":
            c = ord(c) - ord('a')
            if alph[c] == 0:
                alph[c] = 1
                k -= 1
        backtracking('a',k)
        print(mx)