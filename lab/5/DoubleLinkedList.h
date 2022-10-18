#ifndef LAB_5_DOUBLE_LINKED_LIST_H_
#define LAB_5_DOUBLE_LINKED_LIST_H_

#include <iostream>

class DoubleLinkedList {
 public:
  // nested classes
  class Node {
    int data_;
    Node* prev_;
    Node* next_;
   public:
    Node() = default;
    Node(int data, Node* prev, Node* next) {
      data_ = data;
      prev_ = prev;
      next_ = next;
    }
  };

  // ctors and dtors
  DoubleLinkedList();
  ~DoubleLinkedList();

  // methods
  bool add_to_front(int data);
	bool add_to_back(int data);
  bool insert_item(int idx, int data);
  void remove_item(int data);
  void remove_from_front();
	void remove_from_back();

  // operators
  int operator[](int idx);
  friend std::ostream& operator<<(std::ostream& out,
                                  const DoubleLinkedList& lst);

 private:
  Node* head_;
  Node* tail_;
};

using Node = DoubleLinkedList::Node;

#endif // LAB_5_DOUBLE_LINKED_LIST_H_