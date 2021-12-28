# abbab
# axaaxaa

tc = int(input())
words = [input().strip() for _ in range(tc)]

for arr in words:
    ans = 0
    s, e = 0, len(arr)-1
    while s < e:
        if arr[s] == arr[e]:
            s+= 1
            e -= 1
            continue
        if arr[s+1] != arr[e] and arr[s] != arr[e-1]:
            ans = 2
            break

        for left in (0,1):
            i, j = s, e
            if left: i += 1
            else: j -= 1

            is_semi = True
            while i < j:
                if arr[i] != arr[j]:
                    ans = 2
                    is_semi = False
                    break
                i += 1
                j -= 1
            
            if is_semi:
                ans = 1
                break
        break
    print(ans)
