#ifndef CPPDATASTRUCTURES_LINKEDLIST_H
#define CPPDATASTRUCTURES_LINKEDLIST_H
#include "boost/optional.hpp"

class SingleLinkNode
{
public:
  SingleLinkNode(int val): value{val}, next{NULL} {};
  int value;
  SingleLinkNode *next;
};

class SingleLinkedList
{
public:
  SingleLinkNode* head;
  
  SingleLinkedList();
  void push_front(int value);
  boost::optional<int> pop_front();
  boost::optional<int> peek_front();
};
#endif