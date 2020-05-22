class Solution:
    def two_sum(self,nums,target):
        dic={}
        complement = 0
        finalResult = []
        for i in range(len(nums)):
            complement = target - nums[i]
            # print(complement)
            # print(dic)
            listOfIndexes = []
            if(complement in dic):
                listOfIndexes.append(nums[i])
                listOfIndexes.append(complement)
                finalResult.append(listOfIndexes)
            else:
                dic[nums[i]]=i
                # print(dic)
        if len(finalResult) == 0:
            return -1
        return finalResult
    
    def threeSum(self, nums) :
        numsTemp = nums[:]
        finalList = []
        # a + b + c = 0
        # a + c = 0 - b
        
        # a + b = 0 - c

        # a + b
        for i in nums: # O(n) 
            numsTemp.remove(i)
            complement = 0 - i
            candidates = self.two_sum(numsTemp,complement) # O(n)
            # print(result)
            # print()
            if(candidates ==-1):
                numsTemp.append(i)
            else:
                numsTemp.append(i)
                for result in candidates:
                    result.insert(0,i)
                    # print(result)
                    sorted_result = sorted(result)
                    if sorted_result not in finalList:
                        finalList.append(sorted_result)
        return sorted(finalList)

l = [-1,-2,-3,4,1,3,0,3,-2,1,-2,2,-1,1,-5,4,-3]

# expected:    [[-5,1,4],[-5,2,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-2,4],[-2,-1,3],[-2,0,2],[-2,1,1],[-1,-1,2],[-1,0,1]]
# our result:  [[-5, 1, 4], [-5, 2, 3], [-3, -1, 4], [-3, 0, 3], [-3, 1, 2], [-2, -2, 4], [-2, -1, 3], [-2, 0, 2], [-2, 1, 1], [-1, -1, 2], [-1, 0, 1]]
S = Solution()
print(S.threeSum(l))