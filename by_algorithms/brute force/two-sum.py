def solution(nums, target):
    print("INPUT\n", nums, target)
    for i, n in enumerate(nums):
        complement = target - n
    
        if complement in nums[i+1:]:
            # return [nums.index(n), nums[i+1:].index(complement)+(i+1)]
            return [i, nums.index(complement)]

def solution1(nums, target):
    nums_map = {}
    # for i, num in enumerate(nums):
    #     nums_map[num] = i
    
    # for i, num in enumerate(nums):
    #     if target - num in nums_map and i != nums_map[target - num]:
    #         return [i, nums_map[target - num]]
    for i, num in enumerate(nums):
        if target - num in nums_map:
            return [nums_map[target - num], i]
        nums_map[num] = i

print("OUTPUT\n", solution([2,7,11,15], target = 9))