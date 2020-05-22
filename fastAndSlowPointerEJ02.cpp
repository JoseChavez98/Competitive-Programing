#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int value, Node* next = nullptr)
    : value{value}, next{next}
    {}
};

bool has_cycle(Node * head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr and fast->next != nullptr) { 
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
} 

int calculate_cycle_length(Node* ptr) {
    Node *copy = ptr;
    ptr = ptr->next;
    int length = 0;
    while (ptr != copy) {
        ptr = ptr->next;
        length++;
    }
    return length+1;
}

Node* find_start(Node *head, int length) {
    Node* slow = head;
    Node* fast = head;
    for(int i = 0; i <= length; i++) {
        fast = fast->next;
    }
    std::cout<<"aqui\n";
    
    while (fast != nullptr and fast->next != nullptr) { 
        slow = slow->next;
        fast = fast->next;
        if (slow == fast) {
            return slow;
        }
    }
    return nullptr;
}

Node* find_cycle_start(Node * head) {
    Node* slow = head;
    Node* fast = head;
    int length = 0;
    while (fast != nullptr and fast->next != nullptr) { 
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            length = calculate_cycle_length(slow);
            break;
        }
    }
    return find_start(head, length);
} 

 

int main() {

  auto head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->next = new Node(6);
  std::cout << "LinkedList has cycle: " + std::to_string(find_cycle_start(head)->value) << std::endl; 

  head->next->next->next->next->next->next = head->next->next; // 6->3
  std::cout << "LinkedList has cycle: " + std::to_string(find_cycle_start(head)->value) << std::endl;

  head->next->next->next->next->next->next = head->next->next->next;  // 6->4
  std::cout << "LinkedList has cycle: " + std::to_string(find_cycle_start(head)->value) << std::endl;
  return 0; 
}