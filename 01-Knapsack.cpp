#include <iostream>
#include <vector>

typedef std::pair<int, int> item;
typedef std::vector<item> items;

// creates an item with a function with small name
item ci(int a, int b) { return std::make_pair(a, b); }

enum whereFrom { LEFT, UP, NONE };

struct cell {
  int value;
  whereFrom flag = NONE;
  cell(int _value = 0) { value = _value; }
};

int max(int a, int b) { return ((a > b) ? a : b); }

int knapsack(items _items, int maxWeight) {

  cell **table = new cell *[_items.size()];
  for (int i = 0; i < _items.size(); i++) {
    table[i] = new cell[maxWeight + 1];
  }

  for (int item = 0; item < _items.size(); item++) {
    for (int weight = 0; weight < maxWeight + 1; weight++) {
      if (_items[item].second > weight) {
        if (item != 0) {
          table[item][weight] = table[item - 1][weight];
          table[item][weight].flag = UP;
        }
        continue;
      } else if (item - 1 >= 0) {
        int takingItem = _items[item].first +
                         table[item - 1][weight - _items[item].second].value;

        int notTakingItem = table[item - 1][weight].value;

        if (takingItem > notTakingItem) {
          table[item][weight].value = takingItem;
          table[item][weight].flag = LEFT;
        } else {
          table[item][weight].value = notTakingItem;
          table[item][weight].flag = UP;
        }

      } else {
        table[item][weight].value = _items[item].first;
        table[item][weight].flag = LEFT;
      }
    }
  }

  int row = _items.size() - 1;
  int col = maxWeight;

  auto finalCell = table[row][col];

  std::cout << "##################\nITEMS TAKEN\n---------------\n";

  while (finalCell.flag != NONE) {
    if (finalCell.flag == LEFT) {
      std::cout << row << '\n';
      col -= _items[row].second;
      row--;
      finalCell = table[row][col];
    } else {
      row--;
      finalCell = table[row][col];
    }
  }
  std::cout << "##################\nMAX PROFIT\n---------------\n";

  return table[_items.size() - 1][maxWeight].value;
}

int main() {

  //   items _items{ci(1, 2), ci(4, 3), ci(5, 6), ci(6, 7)}; // value - weight
  items _items{ci(60, 5), ci(50, 3), ci(70, 4), ci(30, 2)}; // value - weight

  int maxWeight = 5;

  std::cout << knapsack(_items, maxWeight);

  return 0;
}
