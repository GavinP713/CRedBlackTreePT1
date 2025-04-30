#include "Tree.h"
#include <iostream>
#include <cstring>

using namespace std;

void printTree(Tree* tree, Node* node, int depth);

int main() {
  Tree* tree = new Tree();

  char input[64];

  cout << "Binary Search Tree" << endl;
  cout << "-----------------------------------------------------" << endl;
  cout << endl;
  cout << "add - insert an integer to the tree" << endl;
  cout << "delete - remove an integer from the tree if it exists" << endl;
  cout << "search - search for an integer in the tree" << endl;
  cout << "print - print tree" << endl;
  cout << "quit - quit the program" << endl;
  cout << endl;
  
  while (true) {
    cout << "..." << endl;
    cin >> input;

    if (strcmp(input, "add") == 0) {
      cout << "integer to add: ";
      cin >> input;

      tree->insert(atoi(input));
    }
    else if (strcmp(input, "delete") == 0) {
      cout << "integer to delete: ";
      cin >> input;

      tree->remove(atoi(input)); // ! seg fault when deleting numbers that dont exist !
    }
    else if (strcmp(input, "search") == 0) {
      cout << "integer to search for: ";
      cin >> input;

      Node* node = tree->search(atoi(input));
      if (node != nullptr) cout << "found" << endl;
      else cout << "integer doesnt exist!" << endl;
    }
    else if (strcmp(input, "print") == 0) {
      printTree(tree, tree->head, 0);
    }
    else if (strcmp(input, "quit") == 0) {
      break;
    }

    cout << endl;
  }

  delete tree;
  return 0;
}

void printTree(Tree* tree, Node* node, int depth) {
  if (node->left != nullptr) {
    printTree(tree, node->left, depth + 1);
  }

  for (int d = 0; d < depth; d++) {
    cout << '\t';
  }

  cout << node->value << endl;

  if (node->right != nullptr) {
    printTree(tree, node->right, depth + 1);
  }
}
