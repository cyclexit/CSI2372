#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() {
  len_ = 0;
  head_ = nullptr;
  tail_ = nullptr;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other) {
  len_ = other.len_;
  Node* cur = other.head_;
  while (cur != nullptr) {
    add_to_back(cur->data_);
    cur = cur->next_;
  }
}

DoubleLinkedList::~DoubleLinkedList() {
  if (head_) {
    Node* cur = head_;
    Node* tmp;
    while (cur) {
      tmp = cur;
      cur = cur->next_;
      delete tmp;
    }
    head_ = tail_ = nullptr;
  }
}

int DoubleLinkedList::count_nodes() const {
  return len_;
}

bool DoubleLinkedList::add_to_front(int data) {
  Node* node = new Node(data, nullptr, nullptr);
  if (node == nullptr) return false;
  if (head_) {
    head_->prev_ = node;
    node->next_ = head_;
    head_ = node;
  } else {
    head_ = node;
    tail_ = node;
  }
  // std::cout << __FUNCTION__ << ": head_->data_ = " << head_->data_ << std::endl; // debug
  // std::cout << __FUNCTION__ << ": tail_->data_ = " << tail_->data_ << std::endl; // debug
  ++len_;
  return true;
}

bool DoubleLinkedList::add_to_back(int data) {
  Node* node = new Node(data, nullptr, nullptr);
  if (node == nullptr) return false;
  // std::cout << __FUNCTION__ << ": head_ = " << head_ << std::endl; // debug
  if (tail_) {
    tail_->next_ = node;
    node->prev_ = tail_;
    tail_ = node;
  } else {
    tail_ = node;
    head_ = node;
  }
  // std::cout << __FUNCTION__ << ": head_->data_ = " << head_->data_ << std::endl; // debug
  // std::cout << __FUNCTION__ << ": tail_->data_ = " << tail_->data_ << std::endl; // debug
  ++len_;
  return true;
}

bool DoubleLinkedList::insert_item(int idx, int data) {
  if (idx < 0 || idx >= len_) return false;

  if (idx == 0) return add_to_front(data);
  if (idx == len_ - 1) return add_to_back(data);

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

bool DoubleLinkedList::find(int data) {
  Node* cur = head_;
  while (cur) {
    if (cur->data_ == data) {
      return true;
    }
    cur = cur->next_;
  }
  return false;
}

void DoubleLinkedList::remove_item(int data) {
  Node* cur = head_;
  // NOTE: remove the first node with data_ == data
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
      return;
    }
    cur = nxt;
  }
}

void DoubleLinkedList::remove_from_front() {
  if (head_) {
    // std::cout << __FUNCTION__ << ": head_->data_ = " << head_->data_ << std::endl; // debug
    Node* tmp = head_->next_;
    if (tmp) tmp->prev_ = nullptr;
    if (tail_ == head_) tail_ = tmp;
    delete head_;
    head_ = tmp;
    --len_;
  }
}

void DoubleLinkedList::remove_from_back() {
  if (tail_) {
    // std::cout << __FUNCTION__ << ": head_->data_ = " << head_->data_ << std::endl; // debug
    // std::cout << __FUNCTION__ << ": tail_->data_ = " << tail_->data_ << std::endl; // debug
    Node* tmp = tail_->prev_;
    if (tmp) tmp->next_ = nullptr;
    if (head_ == tail_) head_ = tmp;
    delete tail_;
    tail_ = tmp;
    --len_;
  }
}

int& DoubleLinkedList::operator[](int idx) {
  if (idx >= len_) return dummy_;
  Node* cur = head_;
  while (idx--) cur = cur->next_;
  return cur->data_;
}

std::ostream& operator<<(std::ostream& out, const DoubleLinkedList& lst) {
  Node* cur = lst.head_;
  while (cur != nullptr) {
    if (cur != lst.head_) out << ", ";
    out << cur->data_;
    cur = cur->next_;
  }
  return out;
}
