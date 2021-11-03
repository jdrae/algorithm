n = int(input())

# eratosthenes
is_prime = [1] * (n+1)
is_prime[0] = is_prime[1] = 0
arr = [2]
for i in range(4,n+1,2): is_prime[i] = 0
for i in range(3,n+1,2):
    if not is_prime[i]: continue
    arr.append(i)
    for j in range(i*i,n+1,i*2):
        is_prime[j] = 0

# two pointer
ans, add = 0, 0
s, e = 0,0
while True:
    if add >= n: # 크니까 계속 빼면서 add == n 검사
        add -= arr[s]
        s += 1
    elif e == len(arr): break # 작은데 증가 못시킴
    else:
        add += arr[e]
        e += 1

    if add == n:
        ans += 1
    
print(ans)