#include <iostream>

struct Node {
  int value;
  Node *left = nullptr;
  Node *right = nullptr;
  Node(int _value) { value = _value; }
};

class BinaryTree {
public:
  int value;
  Node *root;
  Node *newRoot;
  Node *tempNode;
  bool flag = false;

  BinaryTree() = default;

  Node *flattenBinaryTree() {

    flattenBinaryTree(root);
    return newRoot;
  }

  void flattenBinaryTree(Node *root) {
    if (root == nullptr)
      return;

    flattenBinaryTree(root->left);

    if (!flag) {
      newRoot = root;
      tempNode = root;
      flag = true;
    } else {
      tempNode->right = root;
      root->left = tempNode;
      tempNode = root;
    }

    flattenBinaryTree(root->right);
  }
};

int main() {
  BinaryTree tree = BinaryTree();
//   tree.root = new Node(1);
//   tree.root->left = new Node(2);
//   tree.root->right = new Node(3);
//   tree.root->left->right = new Node(5);
//   tree.root->left->left = new Node(4);
//   tree.root->left->right->left = new Node(7);
//   tree.root->left->right->right = new Node(8);
//   tree.root->right->left = new Node(6);

    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->left->left = new Node(4);
    tree.root->left->left->right = new Node(9);
    tree.root->left->left->right->left = new Node(10);
    tree.root->right = new Node(3);
    tree.root->right->left = new Node(6);
    tree.root->right->right = new Node(7);
    


  auto root = tree.flattenBinaryTree();
  while (root != nullptr) {
    std::cout << root->value << " <-> ";
    root = root->right;
  }

  return 0;
}