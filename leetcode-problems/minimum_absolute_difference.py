class Solution:
    def minimumAbsDifference(self, arr) :
        arr = sorted(arr)
        finalList = []
        temp = arr[0]
        absolute = (10**6) + 1
        for i in range(1,len(arr)):
            absoluteTemp = arr[i]-temp
            if absoluteTemp < absolute:
                absolute = absoluteTemp
                finalList = []
                finalList.append( (temp, arr[i]) )
            elif absoluteTemp ==absolute:
                finalList.append( (temp, arr[i]) )
            temp=arr[i]
        return finalList

l = [4,2,1,3]                   
d = Solution()
print(d.minimumAbsDifference(l))