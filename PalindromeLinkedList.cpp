// Given the head of a Singly LinkedList, write a method to check if the
// LinkedList is a palindrome or not. Your algorithm should use constant space
// and the input LinkedList should be in the original form once the algorithm is
// finished. The algorithm should have O(N) time complexity where ‘N’ is the
// number of nodes in the LinkedList.

//  1 2 3 4 4 3 2 1

#include <iostream>

struct Node {
  int value;
  Node *next = nullptr;
  Node(int _value) { value = _value; }
};

Node *reverseList(Node *head) {
  Node *reversedHead = NULL;

  while (head != nullptr) {
    Node *tmp = head->next;
    head->next = reversedHead;
    reversedHead = head;
    head = tmp;
  }

  return reversedHead;
}

bool isPalindromicLinkedList(Node *head) {

  Node *prev_slow, *slow = head;
  auto *fast = head;

  if (head != nullptr and head->next != nullptr) {

    while (fast != nullptr and fast->next != nullptr) {
      fast = fast->next->next;
      prev_slow = slow;
      slow = slow->next;
    }
  }

  if (fast == nullptr) {
    auto *temp_slow = slow;
    slow->next = reverseList(slow->next);
    fast = head;
    if (slow->value != prev_slow->value)
      return false;
    slow = slow->next;

    while (slow != nullptr) {
      if (fast->value != slow->value)
        return false;
      fast = fast->next;
      slow = slow->next;
    }
    temp_slow->next = reverseList(temp_slow->next);
    return true;

  } else {
    auto *temp_slow = slow;
    slow->next = reverseList(slow->next);
    fast = head;
    slow = slow->next;

    while (slow != nullptr) {
      if (fast->value != slow->value)
        return false;
      fast = fast->next;
      slow = slow->next;
    }
    temp_slow->next = reverseList(temp_slow->next);
    return true;
  }
}

int main() {
  auto *head = new Node(2);
  head->next = new Node(4);
  head->next->next = new Node(6);

  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(2);

  // head->next->next->next = new Node(6);
  // head->next->next->next->next = new Node(4);
  // head->next->next->next->next->next = new Node(2);

  if (isPalindromicLinkedList(head))
    std::cout << " Is palindrome\n";
  else
    std::cout << " NOT palindrome\n";

    while (head != nullptr) {
      std::cout << head->value << " ";
      head = head->next;
    }

  return 0;
}