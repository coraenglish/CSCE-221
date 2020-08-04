// testing the templated class DLList

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

#include "TemplatedDLList.h"

using namespace std;

int main ()
{
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DLList<string> dll;
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insert_last(ss.str());
  }
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insert_first(ss.str());
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Copy to a new list" << endl;
  DLList<string> dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  cout << "Assign to another new list" << endl;
  DLList<string> dll3;
  dll3 = dll;
  cout << "list3: " << dll3 << endl << endl;
  
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_last();
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_first();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;

  // more testing...
  // add tests for insert_after, insert_before
  // add tests for remove_after, remove_before

    cout << "Delete every other node of list 2 using remove after" << endl;
  for (int i=0; i < dll2.get_size(); i++) {
    dll2.remove_after(*dll2[i]);
  }
  cout << "list: " << dll2 << endl << endl;

  cout << "Delete every other node of list 3 using remove before" << endl;
  for (int i=3; i <= dll3.get_size(); i++) {
    dll3.remove_before(*dll3[i]);
  }
  dll3.remove_before(*dll3[dll3.get_size()-1]);
  cout << "list: " << dll3 << endl << endl;

  cout << "Insert nodes in list 2 using insert after" << endl;
  for (int i=0; i < 20; i+=2) {
    stringstream ss;
    ss << i;
    dll2.insert_after(*dll2[i], ss.str());
  }

  cout << "list: " << dll2 << endl << endl;


  cout << "Insert nodes in list 3 using insert before" << endl;
  for (int i=1; i < 19; i+=2) {
    stringstream ss;
    ss << i;
    dll3.insert_before(*dll3[i], ss.str());
  }

  cout << "list: " << dll3 << endl << endl;

  cout << "Use move constructor to move conents of 2 to 4..." << endl;

  DLList<string> dll4(move(dll2));
  cout << "list4: " << dll4 << endl << endl;


  cout << "Use move assignment operator to move contents of 3 into 5" << endl;
  DLList<string> dll5;
  dll5 = move(dll3);
  cout << "list5: " << dll5 << endl << endl;
  

  cout << "Checking other lists to make sure they are empty" << endl;
  cout << "list2: " << dll2 << endl << endl;
  cout << "list3: " << dll3 << endl << endl;

  cout << "Checking error conditions for list 4 ... " << endl << endl;
  try {
    dll4.remove_before(*dll4[0]);
  } catch (runtime_error& e) {
    cout << "ERROR ... " << e.what() << endl << endl;
  }

  try {
    dll4.insert_before(*dll4[0], "1");
  } catch (runtime_error& e) {
    cout << "ERROR ... " << e.what() << endl << endl;
  }

  return 0;
}
