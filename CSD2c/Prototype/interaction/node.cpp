//
// Created by Mila Louise Maria Philipsen on 26/03/2022.
//

#include "node.h"

Node::Node() {
  std::cout<< "constructor Node" <<std::endl;
}

Node::~Node() {
  std::cout<< "~destructor Node" <<std::endl;
}

Node* Node::makeNewNode(std::string data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void Node::printPreorder(Node *node) {
  if (node == NULL)
    return;

  /* first print data of node */
  std::cout << node->data << " ";

  /* then recur on left subtree */
  printPreorder(node->left);

  /* now recur on right subtree */
  printPreorder(node->right);
}