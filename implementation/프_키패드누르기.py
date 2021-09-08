def solution(numbers, hand):
    answer = ''
    dic = {1:"L", 4:"L", 7:"L", 3:"R", 6:"R", 9:"R", 2:"M", 5:"M", 8:"M", 0:"M"}

    pos = {}
    key = [1,2,3,4,5,6,7,8,9,'*',0,'#']
    curr = 0
    for i in range(4):
        for j in range(3):
            pos[key[curr]] = (i,j)
            curr += 1
    
    l, r = '*', '#'
    for n in numbers:
        if dic[n] != "M":
            answer += dic[n]
            if dic[n] == "L": l = n
            else: r = n
        else:
            ld = abs(pos[n][0] - pos[l][0]) + abs(pos[n][1] - pos[l][1])
            rd = abs(pos[n][0] - pos[r][0]) + abs(pos[n][1] - pos[r][1])
            if ld < rd or (ld == rd and hand == "left"):
                answer += 'L'
                l = n
            elif rd < ld or (ld == rd and hand == "right"):
                answer += 'R'
                r = n
    return answer


print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], 	"right"))
print("LRLLLRLLRRL")