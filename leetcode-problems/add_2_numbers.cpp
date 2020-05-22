#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *l3 =  new ListNode(-1);
    ListNode *temp = new ListNode(-1);
    ListNode *current = new ListNode(-1);
    bool holds = false;
    while (l1->next != nullptr) {
      int sum = l1->val + l2->val;
      (holds) ? sum + 1 : sum + 0;
      if (sum > 9) {
        holds = true;

        current->val = sum % 10;
        if (temp->next != NULL) {
          temp->next = current;
          temp = current;
        } else {
          l3 = current;
          current->next = nullptr;
          temp = current;
        }
      } else {
        holds = false;
        current->val = sum;
        if (temp->next != NULL) {
          temp->next = current;
          temp = current;
        } else {
          l3 = current;
          current->next = nullptr;
          temp = current;
        }
      }
    }
    return l3;

    
    // std::cout<<l3<<'\n'<<temp<<'\n'<<current<<'\n'<<'\n';
    // current->val=l1->val;
    // temp->val=l2->val;
    // current->next=temp;
    // l3 = current;
    // std::cout<<l3<<'\n'<<temp<<'\n'<<current<<'\n'<<'\n';

  }
};
int main() {
    ListNode *l1 = new ListNode(10);
    ListNode *l2 =  new ListNode(11);
    Solution s = Solution();
    s.addTwoNumbers(l1,l2);
     return 0; }