// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

// implementation of the DLList class

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>



using namespace std;

template <typename T>
class DLList; // class declaration

// doubly linked list node
template <typename T>
struct DLListNode {
  T obj;
  DLListNode *prev, *next;
  // constructor
  DLListNode(T e=T(), DLListNode *p = nullptr, DLListNode *n = nullptr)
    : obj(e), prev(p), next(n) {}
};

// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error {
  explicit EmptyDLList(char const* msg=nullptr): runtime_error(msg) {}
};

struct OutOfBounds : public std::runtime_error {
  explicit OutOfBounds(char const* msg=nullptr): runtime_error(msg) {}
};

struct IllegalRemoval : public std::runtime_error {
  explicit IllegalRemoval(char const* msg=nullptr): runtime_error(msg) {}
};

struct IllegalInsertion : public std::runtime_error {
  explicit IllegalInsertion(char const* msg=nullptr): runtime_error(msg) {}
};


// doubly linked list class
template <typename T>
class DLList {
private:
  DLListNode<T> header, trailer;
  int size;
public:
  DLList() : header(T()), trailer(T()), size(0) // default constructor
  { header.next = &trailer; trailer.prev = &header; }
  DLList(const DLList<T> & dll); // copy constructor
  DLList(DLList<T>&& dll); // move constructor
  ~DLList(); // destructor
  DLList<T>& operator=(const DLList<T>& dll); // copy assignment operator
  DLList<T>& operator=(DLList<T>&& dll); // move assignment operator
  // return the pointer to the first node
  DLListNode<T> *first_node() const { return header.next; } 
  // return the pointer to the trailer
  const DLListNode<T> *after_last_node() const { return &trailer; }
  // return if the list is empty
  bool is_empty() const { return header.next == &trailer; }
  T first() const; // return the first object
  T last() const; // return the last object
  T remove_first(); // remove the first node
  void insert_last(T obj); // insert to the last node
  int get_size() const;
};

// output operator
template <typename T>
ostream& operator<<(ostream& out, const DLList<T>& dll);


// copy constructor
template <typename T>
DLList<T>::DLList(const DLList<T>& dll)
{
  size = dll.size;
  header.next = &trailer;
  trailer.prev = &header;
  size = 0;
  if (dll.is_empty()) {
    return;
  }
  DLListNode<T>* current = dll.header.next;
  while (current->next) {
      this->insert_last(current->obj);
      current = current->next;
  }
}

// move constructor
template <typename T>
DLList<T>::DLList(DLList<T>&& dll)
{
  size = dll.size;
  header = dll.header;
  trailer = dll.trailer;
  header.next->prev = &header;
  trailer.prev->next = &trailer;
  dll.header.next = &dll.trailer;
  dll.trailer.prev = &dll.header;
  dll.size = 0;
}

// copy assignment operator
template <typename T>
DLList<T>& DLList<T>::operator=(const DLList<T>& dll)
{
  size = 0;
  if (this != &dll) {
    DLListNode<T> *prev_node, *node = header.next;
    while (node != &trailer) {
      prev_node = node;
      node = node->next;
      delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
    DLListNode<T>* current = dll.header.next;
      while (current->next) {
          this->insert_last(current->obj);
          current = current->next;
      }
  }
  return *this;
}

// move assignment operator
template <typename T>
DLList<T>& DLList<T>::operator=(DLList<T>&& dll)
{
  if (this != &dll) {
    size = dll.size;
    header = dll.header;
    trailer = dll.trailer;
    header.next->prev = &header;
    trailer.prev->next = &trailer;
    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
    dll.size = 0;
  }
  return *this;
}

// destructor
template <typename T>
DLList<T>::~DLList()
{
  DLListNode<T> *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
  size = 0;
}


// insert a new object as the last one
template <typename T>
void DLList<T>::insert_last(T obj)
{
  DLListNode<T> *node = new DLListNode<T>(obj, trailer.prev, &trailer);
  trailer.prev->next = node;
  trailer.prev = node;
  size++;
}

// remove the first node from the list
template <typename T>
T DLList<T>::remove_first()
{ 
  if (is_empty()) {
    throw EmptyDLList("Empty linked list");
  }
  DLListNode<T> *temp = header.next;
  temp->next->prev = &header;
  header.next = temp->next;
  T obj = temp->obj;
  delete temp;
  --size;
  return obj;

}


// return the first object (do not remove)
template <typename T>
T DLList<T>::first() const
{ 
  if (is_empty()) {
    throw EmptyDLList("Empty linked list");
  }
  return header.next->obj;
}

// return the last object (do not remove)
template <typename T>
T DLList<T>::last() const
{
  if (is_empty()) {
    throw EmptyDLList("Empty linked list");
  }
  return trailer.prev->obj;
}




// Helper Functions

template <typename T>
int DLList<T>::get_size() const 
{
  return size;
}


template <typename T>
ostream& operator<<(ostream& os, const DLList<T>& dll) 
{  
  const DLListNode<T> *curr = dll.first_node();
  os << std::endl << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
  os << "header.next: " << dll.first_node()->prev << std::endl;
  os << "trailer.prev: " << dll.after_last_node() << std::endl;
  os << "size: " << dll.get_size() << std::endl;
  os << std::setw(16) << "node" << std::setw(16) << "node.prev" << std::setw(16) << "node.data" <<  std::setw(16) << "node.next" << std::endl;
  while (curr->next) {
      os << std::setw(16) << curr;
      os << std::setw(16) << curr->prev;
      os << std::setw(16) << curr->obj;
      os << std::setw(16) << curr->next;
      os << std::endl;
      curr = curr->next;
  }
  os << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
  return os;
}




#endif
