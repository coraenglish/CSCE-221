#ifndef MINQUEUE
#define MINQUEUE

#include "TemplatedDLList.h"
#include <iomanip>
#include <string>
#include <sstream>

template <typename T>
class MinQueue {
private:
    DLList<T> dll;
public:
    MinQueue() : dll() {} 
    ~MinQueue() { dll.~DLList(); }
    void enqueue(T x) { dll.insert_last(x); }
    T dequeue() { return dll.remove_first(); }
    int size() const { return dll.get_size(); }
    bool is_empty() const { return dll.is_empty(); }
    T min();
    DLListNode<T>* first() const { return dll.first_node(); }
    const DLListNode<T>* last() const { return dll.after_last_node(); }
};


template <typename T>
T MinQueue<T>::min() 
{
    if (dll.is_empty()) {
        throw EmptyDLList("Empty queue");
    }
    DLListNode<T>* curr = dll.first_node();
    T min = curr->obj;
    while(curr != dll.after_last_node()) {
        if (curr->obj < min) {
            min = curr->obj;
        }
        curr = curr->next;
    }
    return min;
}

template <typename T>
ostream& operator<<(ostream& os, const MinQueue<T>& mq) 
{  
  const DLListNode<T> *curr = mq.first();
  os << std::endl << std::setfill('-') << std::setw(80) << '-' << std::setfill(' ') << std::endl;
  os << "header.next: " << mq.first()->prev << std::endl;
  os << "trailer.prev: " << mq.last() << std::endl;
  os << "size: " << mq.size() << std::endl;
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