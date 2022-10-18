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
  return insert_item(0, data);
}

bool DoubleLinkedList::add_to_back(int data) {
  return insert_item(len_, data);
}

bool DoubleLinkedList::insert_item(int idx, int data) {
  if (idx < 0 || idx > len_) return false;

  Node* node = new Node(data, nullptr, nullptr);
  if (node == nullptr) return false;

  Node* cur = head_;
  for (int i = 0; i < idx - 1; ++i) {
    cur = cur->next_;
  }
  node->prev_ = cur;
  node->next_ = cur ? cur->next_ : nullptr;
  if (cur) {
    if (cur->next_) cur->next_->prev_ = node;
    cur->next_ = node;
  }
  if (!head_) head_ = node;
  if (!tail_) tail_ = node;

  ++len_;
  return true;
}

void DoubleLinkedList::remove_item(int data) {

}
