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

std::string Node::printPreorder(Node *node) {
  if (node == NULL)
    return "";

  std::string question = node->data;



  return question;
}

std::string Node::printRoot(Node *node, int questionSelect) {
  //0 = left
  //1 = right
  if (node == NULL)
    return "";

  std::string question = node->data;
    return question;
}

std::string Node::printLeaf(Node *node, int questionSelect) {
  std::string question;
  if(questionSelect == 0){
    question = node->left->data;
  }else{
    question = node->right->data;
  }
  return question;
}
