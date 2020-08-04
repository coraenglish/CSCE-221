// implementation of the DLList class

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "DLList.h"

////////////////////////////////////////////////////
///                   Read Me                    ///
///     The output operator was modified from    ///
///     a previously written DLL program in      ///
///     CSCE 121. Also, I added a size variable  ///
///     that is private in the DLList class      ///
///     and a getter function for this.          ///
////////////////////////////////////////////////////


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

// copy constructor
DLList::DLList(const DLList& dll)
{
  size = dll.size;
  header.next = &trailer;
  trailer.prev = &header;
  size = 0;
  
  if (dll.is_empty()) {
    return;
  }

  DLListNode* current = dll.header.next;
  while (current->next) {
      this->insert_last(current->obj);
      current = current->next;
  }
}

// move constructor
DLList::DLList(DLList&& dll)
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
DLList& DLList::operator=(const DLList& dll)
{
  size = 0;
  if (this != &dll) {
    DLListNode *prev_node, *node = header.next;
    while (node != &trailer) {
      prev_node = node;
      node = node->next;
      delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
    DLListNode* current = dll.header.next;
      while (current->next) {
          this->insert_last(current->obj);
          current = current->next;
      }
  }
  return *this;
}

// move assignment operator
DLList& DLList::operator=(DLList&& dll)
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
DLList::~DLList()
{
  DLListNode *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
  size = 0;
}

// insert a new object as the first one
void DLList::insert_first(int obj)
{ 
  DLListNode *node = new DLListNode(obj, &header, header.next);
  header.next->prev = node;
  header.next = node;
  size++;
}

// insert a new object as the last one
void DLList::insert_last(int obj)
{
  DLListNode *node = new DLListNode(obj, trailer.prev, &trailer);
  trailer.prev->next = node;
  trailer.prev = node;
  size++;
}

// remove the first node from the list
int DLList::remove_first()
{ 
  if (is_empty()) {
    throw EmptyDLList("Empty linked list");
  }
  DLListNode *temp = header.next;
  temp->next->prev = &header;
  header.next = temp->next;
  int obj = temp->obj;
  delete temp;
  --size;
  return obj;

}

// remove the last node from the list
int DLList::remove_last()
{
  if (is_empty()) {
    throw EmptyDLList("Empty linked list");
  }
  DLListNode *temp = trailer.prev;
  temp->prev->next = &trailer;
  trailer.prev = temp->prev;
  int obj = temp->obj;
  delete temp;
  --size;
  return obj;
}

// return the first object (do not remove)
int DLList::first() const
{ 
  if (is_empty()) {
    throw EmptyDLList("Empty linked list");
  }
  return header.next->obj;
}

// return the last object (do not remove)
int DLList::last() const
{
  if (is_empty()) {
    throw EmptyDLList("Empty linked list");
  }
  return trailer.prev->obj;
}

// insert a new node after the node p
void DLList::insert_after(DLListNode &p, int obj)
{
  if (is_empty()) {
    throw EmptyDLList("Empty linked list");
  }
  if (&trailer == &p) {
    throw IllegalInsertion("Insert after trailer");
  }
  DLListNode* node = new DLListNode(obj, &p, p.next);
  p.next->prev = node;
  p.next = node;  
  size++;
}

// insert a new node before the node p
void DLList::insert_before(DLListNode &p, int obj)
{
  if (is_empty()) {
    throw EmptyDLList("Empty linked list");
  }
  if (&header == &p) {
    throw IllegalInsertion("Insert before head");
  }
  DLListNode* node = new DLListNode(obj, p.prev, &p);
  p.prev->next = node;
  p.prev = node; 
  size++;
}

// remove the node after the node p
int DLList::remove_after(DLListNode &p)
{
  if (is_empty()) {
    throw EmptyDLList("Empty linked list");
  }
  if (&trailer == &p || trailer.prev == &p) {
    throw IllegalRemoval("Remove from end");
  }
  DLListNode *temp = p.next;
  temp->next->prev = &p;
  p.next = temp->next;
  int obj = temp->obj;
  delete temp;
  size--;
  return obj;

}

// remove the node before the node p
int DLList::remove_before(DLListNode &p)
{
  if (is_empty()) {
    throw EmptyDLList("Empty linked list");
  }
  if (&header == &p || header.next == &p) {
    throw IllegalRemoval("Remove from front");
  }
  DLListNode *temp = p.prev;
  temp->prev->next = &p;
  p.prev = temp->prev;
  int obj = temp->obj;
  delete temp;
  size--;
  return obj;

}

// Helper Functions

int DLList::get_size() const 
{
  return size;
}

ostream& operator<<(ostream& os, const DLList& dll) 
{  
  const DLListNode *curr = dll.first_node();
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

DLListNode* DLList::operator[](int idx) {
  if (idx >= size || idx < 0) {
    throw OutOfBounds("Out of bounds");
  }
  DLListNode* temp = &header;
  for (int i = 0; i < idx; ++i) {
    temp = temp->next;
  }
  return temp;
}
