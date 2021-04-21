comp2 = ["c=", "c-", "d-", "lj", "nj", "s=", "z="]
comp3 = "dz="

s = input()
ans = 0
i = 0
while i < len(s):
    c = s[i:i+2]
    find = False
    for comp in comp2:
        if c.find(comp) == -1:
            continue
        i+=2
        find = True
        break
    if not find and s[i:i+3] == comp3:
        i+=3
        find = True
    if not find:
        i+=1
    ans+=1
print(ans)