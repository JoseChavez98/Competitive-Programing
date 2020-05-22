#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::vector<int> index;
    std::map<int, int> hashTable;
    int complement = 0;
    for (int i = 0; i < nums.size(); i++) {
      complement = target - nums[i];
      if (hashTable.find(complement) != hashTable.end()) {
        index.push_back(i);
        index.push_back(hashTable[complement]);
      }
      hashTable[nums[i]] = i;
    }
    std::sort(index.begin(), index.end());
    return index;
  }

  void printVector(std::vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      std::cout << nums[i] << " ";
    }
  }
};

int main() {
  std::vector<int> vec{7, 15, 2, 11};
  auto solved = Solution();
  auto newV = solved.twoSum(vec, 9);
  for (auto &i : newV) {
    std::cout << i << " ";
  }

  return 0;
}