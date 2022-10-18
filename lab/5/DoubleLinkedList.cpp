#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() {
  len_ = 0;
  head_ = nullptr;
  tail_ = nullptr;
}

DoubleLinkedList::~DoubleLinkedList() {
  // TODO: implement this
}

bool DoubleLinkedList::add_to_front(int data) {
  // NOTE: this means nothing in the linked list,
  //       so we also need to update tail_
  Node* node = new Node(data, nullptr, head_);
  if (node == nullptr) return false;
  head_ = node;
  if (tail_ == nullptr) tail_ = node;
  ++len_;
  return true;
}
