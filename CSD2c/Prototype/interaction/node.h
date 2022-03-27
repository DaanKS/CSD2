//After original code by https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
#include <iostream>
#ifndef INTERACTION_NODE_H
#define INTERACTION_NODE_H


class Node {
public:
    Node();
    ~Node();
    Node* makeNewNode(std::string data);
    std::string printPreorder(Node* node);
    std::string printRoot(Node* node, int questionSelect);
    std::string printLeaf(Node* node, int questionSelect);
    std::string data;
    struct Node *left, *right;
};


#endif //INTERACTION_NODE_H
