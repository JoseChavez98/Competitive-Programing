// Given the head of a Singly LinkedList, write a method to modify the
// LinkedList such that the nodes from the second half of the LinkedList are
// inserted alternately to the nodes from the first half in reverse order. So if
// the LinkedList has nodes 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null, your method
// should return 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null. Your algorithm should not
// use any extra space and the input LinkedList should be modified in- place.

#include <iostream>

struct Node {
  int value;
  Node *next = nullptr;
  Node(int _value) { value = _value; }
};

void printList(Node *head) {
  std::cout << '\n';
  while (head != nullptr) {
    std::cout << head->value << " ";
    head = head->next;
  }
  std::cout << '\n';
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

void computeList(Node *head) {
  Node *prev_slow, *slow, *fast;
  slow = fast = head;

  if (head != nullptr and head->next != nullptr) {
    while (fast != nullptr and fast->next != nullptr) {
      fast = fast->next->next;
      prev_slow = slow;
      slow = slow->next;
    }

    slow->next = reverseList(slow->next);
    slow = slow->next;
    prev_slow->next->next = nullptr;

    Node *first, *second;
    first = head;
    second = head->next;

    while (slow) {
      first->next = slow;
      slow = slow->next;
      first->next->next = second;
      
      first = first->next->next;
      second = second->next;
    }
  }
};

int main() {
  auto *head = new Node(2);
  head->next = new Node(4);
  head->next->next = new Node(6);
  head->next->next->next = new Node(8);
  head->next->next->next->next = new Node(10);
  head->next->next->next->next->next = new Node(12);

  computeList(head);

  printList(head);

  return 0;
}