def two_sum(nums,target):
    dic={}
    complement = 0
    listOfIndexes = []
    for i in range(len(nums)-1):
        complement = target - nums[i]
        if(complement in dic):
            listOfIndexes.append(i)
            listOfIndexes.append(dic[complement])
            return listOfIndexes
        else:
            dic[nums[i]]=i
    return -1

listOfNumbers = [2,7,11,15]
print(sorted(two_sum(listOfNumbers,9)))