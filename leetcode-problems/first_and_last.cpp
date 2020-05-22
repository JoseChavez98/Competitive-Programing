#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid, l = 0,r=nums.size()-1;
        std::vector<int>finalList;
            while(l<=r){
                mid= l+(r-l)/2;
                
                if(nums[mid]==target){
                    finalList.push_back(mid);
                    if(nums[mid])
                }
                else if(nums[mid]<target){
                    l = mid+1;                     
                }
                else{
                    r =mid -1;
                }
            }
        return finalList;
    }
};

int main(){

    std::vector<int> vec{5,7,7,8,8,10};
    auto S = Solution();
    auto res = S.searchRange(vec,8);
    for(auto &i : res){
        std:cout<<i<<" ";
    }

    return 0;
}