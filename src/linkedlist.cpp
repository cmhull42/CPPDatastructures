#include <iostream>
#include "boost/optional.hpp"
#include "linkedlist.h"

SingleLinkedList::SingleLinkedList() {
    this->head = NULL;
}

void SingleLinkedList::push_front(int value) {
    SingleLinkNode *node = new SingleLinkNode(value);
    if (this->head == NULL) {
        this->head = node;
        return;
    }

    node->next = this->head;
    this->head = node;
}

boost::optional<int> SingleLinkedList::peek_front() {
    if (this->head == NULL) {
        return boost::optional<int>{};
    }
    return this->head->value;
}

boost::optional<int> SingleLinkedList::pop_front() {
    if (this->head == NULL) {
        return boost::optional<int>{};
    }
    SingleLinkNode* node = this->head;
    this->head = node->next;
    int value = node->value;
    delete node;

    return value;
}