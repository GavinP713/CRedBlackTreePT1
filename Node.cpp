#include "Node.h"

Node::Node(int _value, Node* _parent) {
  parent = _parent;
  left = nullptr;
  right = nullptr;
  value = _value;
}
