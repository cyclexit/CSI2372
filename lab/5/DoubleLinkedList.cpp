#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() {
  len_ = 0;
  head_ = nullptr;
  tail_ = nullptr;
}

DoubleLinkedList::~DoubleLinkedList() {
  // TODO: implement this
}

int DoubleLinkedList::count_nodes() const {
  return len_;
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
  Node* cur = head_;
  // NOTE: remove all nodes with data_ == data
  while (cur) {
    Node* nxt = cur->next_;
    if (cur->data_ == data) {
      if (cur == head_) {
        remove_from_front();
      } else if (cur == tail_) {
        remove_from_back();
      } else {
        cur->prev_->next_ = cur->next_;
        cur->next_->prev_ = cur->prev_;
        delete cur;
        --len_;
      }
    }
    cur = nxt;
  }
}

void DoubleLinkedList::remove_from_front() {
  if (head_) {
    Node* tmp = head_->next_;
    if (tail_ == head_) tail_ = tmp;
    delete head_;
    head_ = tmp;
    --len_;
  }
}

void DoubleLinkedList::remove_from_back() {
  if (tail_) {
    Node* tmp = tail_->prev_;
    if (tmp) tmp->next_ = nullptr;
    if (head_ == tail_) head_ = tmp;
    delete tail_;
    tail_ = tmp;
    --len_;
  }
}

int& DoubleLinkedList::operator[](int idx) const {
  Node* cur = head_;
  while (idx--) cur = cur->next_;
  return cur->data_;
}

std::ostream& operator<<(std::ostream& out, const DoubleLinkedList& lst) {
  for (int i = 0; i < lst.len_; ++i) {
    if (i) out << ", ";
    out << lst[i];
  }
  return out;
}
