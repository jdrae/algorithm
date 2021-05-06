def solution(logs):
    print("INPUT\n", logs)
    letters, digits = [], []
    for log in logs:
        if log.split()[1].isdigit(): # 숫자 판별
            digits.append(log)
        else:
            letters.append(log)
    
    letters.sort(key = lambda x : (x.split()[1:], x.split()[0])) # 문자순(1)으로 정렬하되, 문자가 동일하면 식별자(0) 순
    return letters+digits

print("OUTPUT\n", solution(["dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"]))

