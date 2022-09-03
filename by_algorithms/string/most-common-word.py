import re
import collections
def solution(paragraph, banned):
    print("INPUT\n", paragraph, banned)
    words = [word for word in re.sub(r'[^\w]', ' ', paragraph) # 단어 문자(word character) 가 아닌 모든 문자를 공백으로 치환
            .lower().split()
                if word not in banned]

    # counts = collections.defaultdict(int) # 키 존재 유무를 확인할 필요 없음
    # for word in words:
    #     counts[word] += 1

    counts = collections.Counter(words)
    # return counts.most_common(1)[0][0] # [('ball',2)]
    
    return max(counts, key=counts.get) # dict value 가 최대인 key

print("OUTPUT\n", solution(paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned=["hit"]))