import math

def change(n, k):
    ret = ''
    while n > 0:
        n, mod = divmod(n, k)
        ret += str(mod)
    return ret[::-1]

def prime_to(n):
    is_prime = [1] * n
    is_prime[0] = is_prime[1] = 0
    for i in range(4,n,2):
        is_prime[i] = 0
    for i in range(3,n,2):
        if not is_prime[i]: continue
        for j in range(i*i, n, i*2):
            is_prime[j] = 0
    return is_prime

def check_prime(n):
    is_prime = True
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            is_prime= False
            break
    return is_prime

def solution(n, k):
    answer = 0
    is_prime = prime_to(n+1)
    new = change(n,k)
    for num in new.split("0"):
        if num == '': continue
        num = int(num)
        if num > n:
            if check_prime(n):
                answer += 1
        else:
            if is_prime[num]:
                answer += 1
    return answer

print(solution(997244,3))