def quadSumTarget(nums, target):
        nums.sort()
        ans = []
        for a in range(len(nums)-3):
            if a > 0 and nums[a] == nums[a-1]:
                continue
            for b in range(a+1,len(nums)-2):
                if b > a+1 and nums[b] == nums[b-1]:
                    continue
                c, d = b+1, len(nums)-1
                while c < d:
                    tot = nums[a]+nums[b]+nums[c]+nums[d]
                    if tot == target:
                        ans.append([nums[a],nums[b],nums[c],nums[d]])
                    if tot <= target:
                        c += 1
                        while nums[c] == nums[c-1] and c < d:
                            c += 1
                    if tot >= target:
                        d -= 1
                        while nums[d] == nums[d+1] and c < d:
                            d -= 1
        return ans

print(quadSumTarget([4, 1, 2, -1, 1, -3],1))