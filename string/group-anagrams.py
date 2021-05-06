import collections
def solution(strs):
    print("INPUT\n", strs)
    anagrams = collections.defaultdict(list)
    for word in strs:
        anagrams[''.join(sorted(word))].append(word) # 문자열 내부 정렬후 다시 문자열로
    return list(anagrams.values())

print("OUTPUT\n", solution(["eat","tea","tan","ate","nat","bat"]))