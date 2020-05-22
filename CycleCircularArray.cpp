// We are given an array containing positive and negative numbers. Suppose the
// array contains a number ‘M’ at a particular index. Now, if ‘M’ is positive we
// will move forward ‘M’ indices and if ‘M’ is negative move backwards ‘M’
// indices. You should assume that the array is circular which means two things:
// 1. If, while moving forward, we reach the end of the array, we will jump to
// the first element to continue the movement.
// 2. If, while moving backward, we reach the beginning of the array, we will
// jump to the last element to continue the movement. Write a method to
// determine if the array has a cycle. The cycle should have more than one
// element and should follow one direction which means the cycle should not
// contain both forward and backward movements.

#include <iostream>
#include <vector>

typedef std::vector<int> array;
typedef array::iterator arrayIterator;

enum direction { POSITIVE, NEGATIVE };

direction calculateDirection(arrayIterator iter) {
  return ((*iter >= 0) ? POSITIVE : NEGATIVE);
}

void operateIterator(array &arr, arrayIterator &iter) {
  auto direct = calculateDirection(iter);
  int cont = 0;
  int roof = *iter;

  if (direct == POSITIVE) {
    while (cont < roof) {
      iter++;
      if (iter == arr.end())
        iter = arr.begin();
      cont++;
    }

  } else if (direct == NEGATIVE) {
    while (cont < abs(roof)) {
      if (iter == arr.begin()) {
        iter = arr.end();
        iter--;
        cont++;
      } else {
        iter--;
        cont++;
      }
    }
  }
}

bool detectCicle(array &arr, arrayIterator iter) {

  auto firstDirec = calculateDirection(iter);
  arrayIterator slow = iter;
  arrayIterator fast = iter;
  bool firstSTep = true;

  while (true) {
    auto tempDirectSlow = calculateDirection(slow);
    auto tempDirectFast = calculateDirection(fast);

    if (tempDirectSlow != firstDirec or tempDirectFast != firstDirec)
      return false;

    operateIterator(arr, slow);
    operateIterator(arr, fast);
    operateIterator(arr, fast);

    if (firstSTep) {
      if (slow == fast)
        return false;
      firstSTep = false;
    }

    if (slow == fast) {
      return true;
    }
  }
  return false;
};

bool circularArray(array &arr) {
  auto iter = arr.begin();
  for (; iter != arr.end(); iter++) {
    if (detectCicle(arr, iter))
      return true;
  }
  return false;
};

int main() {
  array arr{1, 2, -1, 2, 2};
  array arr1{2, 2, -1, 2};
  array arr2{2, 1, -1, -2};
  array arr3{-1,2};
  array arr4{4,-5,-4};

  std::cout << circularArray(arr)<<'\n';
  std::cout << circularArray(arr1)<<'\n';
  std::cout << circularArray(arr2)<<'\n';
  std::cout << circularArray(arr3)<<'\n';
  std::cout << circularArray(arr4)<<'\n';

  return 0;
}