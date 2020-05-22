#include <bits/stdc++.h>
#include <iostream>

typedef std::pair<int, int> myPair;

// xy#z

myPair computeWord(std::string &word) {
  int countOfBS = 0;
  int p1 = word.size() - 1;
  int p2 = word.size() - 1;

  for (; p2 >= 0; p2--) {
    if (word[p2] == '#') {
      countOfBS++;
    } else if (word[p2] != '#') {
      if (countOfBS != 0) {
        countOfBS--;
      } else {
        word[p1] = word[p2];
        p1--;
      }
    }
  }
  myPair newp = std::make_pair(p1+1,word.size()-1);

  return newp;
}

bool backSpaces(std::string word1, std::string word2) {
  auto value1 = computeWord(word1);
    auto value2 = computeWord(word2);

    if(value1.second-value1.first+1 !=
    value2.second-value2.first+1) return false;

    auto start1 = value1.first;
    auto end1 = value1.second;
    auto start2 = value2.first;
    auto end2 = value2.second;

    while(start1<=end1){
        if(word1[start1]!=word2[start2]){
            return false;
        }
        start1++;
        start2++;
    }
    return true;
}

int main() {

  std::cout<<backSpaces("xy#z", "xzz#")<<'\n';
  std::cout<<backSpaces("xy#z","xyz#")<<'\n';
  std::cout<<backSpaces("xp#","xyz##")<<'\n';
  return 0;
}