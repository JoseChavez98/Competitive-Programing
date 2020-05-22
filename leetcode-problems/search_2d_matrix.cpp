#include <cmath>
#include <cstring>
#include <iostream>
#include <memory>
#include <vector>
typedef std::pair<int, int> Pair;

class Solution {
public:
  bool binary_search(int *array, int begin, int end, int target) {
    if (begin <= end) {
      auto mid = begin + (end - begin) / 2;
      if (array[mid] == target) {
        return true;
      }
      if (target < array[mid]) {
        end = mid - 1;
      } else {
        begin = mid + 1;
      }
      return binary_search(array, begin, end, target);
    }
    return false;
  }
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
//     auto n = matrix.size();
//     auto m = matrix[0].size();

//     int *array = new int[n * m];
//     auto *pp = matrix.data();
//     for (auto i = 0; i < n; i++) {
//       int *row = (int *)pp[i].data();
//       std::memcpy(array + i * m, row, sizeof(int) * m);
//     }
//     return binary_search(array, 0, n * m, target);
//   }
  if(matrix.size()==0) return false;
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() and j>=0){
                if(matrix[i][j]>target) j--;
                else if(matrix[i][j]<target) i++;
                else return true;
        }
        return false;
  }
};

int main() {

  std::vector<std::vector<int>> matrix{{1}};
//    {
//     {1, 3, 5, 7}, {10, 11, 16, 20}, { 23, 30, 34, 50 }
//   };
//   {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
  auto S = Solution();
  (S.searchMatrix(matrix, 2)) ? std::cout << "true" : std::cout << "false";
  return 0;
}