#include <iostream>

struct Node{
  int value;
  Node *left;
  Node *right;
  Node (int i = 0): value(i), left(nullptr), right(nullptr){}
};

auto left  = &Node::left;
auto right = &Node::right;

//Traverse tree using fold expression
template<typename T, typename... TP>
Node* traverse(T np, TP... paths)
{
  return (np ->* ... ->* paths);//np->*paths1->*paths2..
}


int main()
{
  //Init binary tree structure
  Node* root = new Node(0);
  root->left = new Node(1);
  root->left->right = new Node(2);

  //Traverse binary tree
  Node* node = traverse(root, left, right);

  std::cout << "Node value: " << node->value << std::endl;

  delete root->left->right, delete root->left, delete root;

  return 0;
}
