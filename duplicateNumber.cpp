#include <iostream>

enum way {
    NORMAL,
    BY_ONE
};

void traversePointersTillEqual(int arr[],int &slow,int &fast,way flag){
  if (flag == NORMAL) {

    while (slow != fast) {
      slow = arr[slow];
      fast = arr[fast];
      fast = arr[fast];
    }
  } else {
    while (slow != fast) {
      slow = arr[slow];
      fast = arr[fast];
    }
  }
}

int findDuplicate(int arr[]) {
  int slow = arr[0];

  int fast = arr[0];
  fast = arr[fast];
  fast = arr[fast];

  traversePointersTillEqual(arr, slow, fast,NORMAL);

  int cycleLength = 0;
  fast = arr[fast];

  while (slow != fast) {
    fast = arr[fast];
    cycleLength += 1;
  }

  slow = fast = arr[0];

  while (cycleLength >= 0) {
    fast = arr[fast];
    cycleLength--;
  }

  traversePointersTillEqual(arr,slow,fast,BY_ONE);

  return slow;
}

int main() {
  int arr[] = {1, 4, 6, 2, 6, 3, 5};
  int arr1[] = {1, 1};
  int arr2[] = {1, 2, 3, 4, 5, 6, 1};
  int arr3[] = {1, 2, 3, 3, 4, 5, 6};
  int arr4[] = {1, 4, 6, 2, 5, 3, 5};

  std::cout << findDuplicate(arr) << '\n';
  std::cout << findDuplicate(arr1) << '\n';
  std::cout << findDuplicate(arr2) << '\n';
  std::cout << findDuplicate(arr3) << '\n';
  std::cout << findDuplicate(arr4) << '\n';
}
