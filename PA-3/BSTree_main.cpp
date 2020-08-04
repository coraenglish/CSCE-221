
#include <iostream>
#include <fstream>
#include <string>
#include "BSTree.h"

BSTree read_file(string file_name)
{
  /*
    open the file and use the input operator (operator>>)
    to construct a new tree
  */
  BSTree new_tree;
  ifstream infile(file_name);
  if (!infile.is_open()){
    cout << "Invalid file" << endl;
    exit(1);
  }
  // use >> to read in to new_tree
  infile >> new_tree;
  return new_tree;
}


int main()
{
  ////////////////////////////////////////////////////////////
  //    main I created to test different copy/move funcs    //
  ////////////////////////////////////////////////////////////

  // test the default constructor
  // BSTree BST1;
  // BST1.insert(5);
  // BST1.insert(3);
  // BST1.insert(9);
  // BST1.insert(7);
  // BST1.insert(10);
  // BST1.insert(11);
  // cout << "BST 1 Default Constructor and Insert Check: " << endl;
  // BST1.inorder(std::cout);
  // cout << endl;
  // BST1.print_level_by_level(std::cout);
  // cout << endl;

  // // test the search function
  // cout << "Search for node with value 9. \nFound node with value, searchtime: " << *BST1.search(9) << endl << endl;
 
  // // test the copy constructor
  // BSTree BST2(BST1);
  // cout << "BST 2 Copy (with 1) Constructor Check: " << endl;
  // BST2.inorder(std::cout);
  // cout << endl;
  // BST2.print_level_by_level(std::cout);
  // cout << endl;

  // // test the move constructor
  // BSTree BST3(move(BST2));
  // cout << "BST 3 Move (with 2) Constructor Check: " << endl;
  // BST3.inorder(std::cout);
  // cout << endl;
  // BST3.print_level_by_level(std::cout);
  // cout << endl;

  // cout << "BST 2 Move Constructor Check (should be empty): " << endl;
  // BST2.inorder(std::cout);
  // cout << endl;
  // BST2.print_level_by_level(std::cout);
  // cout << endl;

  // // test the copy assignment
  // cout << "BST 4 Copy (with 1) Assignment Check: " << endl;
  // BSTree BST4 = BST1;
  // BST4.inorder(std::cout);
  // cout << endl;
  // BST4.print_level_by_level(std::cout);
  // cout << endl;

  // // test the copy assignment
  // cout << "BST 5 Copy (with 4) Assignment Check: " << endl;
  // BSTree BST5;
  // BST5 = move(BST4);
  // BST5.inorder(std::cout);
  // cout << endl;
  // BST5.print_level_by_level(std::cout);
  // cout << endl;

  // cout << "BST 4 Move Assignment Check (should be empty): " << endl;
  // BST4.inorder(std::cout);
  // cout << endl;
  // BST4.print_level_by_level(std::cout);
  // cout << endl;


  //////////////////////////////////////////////////////////////////////
  //    original main function with added part to output to files     //
  //////////////////////////////////////////////////////////////////////
 
  for(int i = 1; i <= 12; i++) {
    string dir= "data-files/"+std::to_string(i);
    BSTree l = read_file(dir+"l");
    cout << "average search time linear " << i << " "
	 << l.get_average_search_time() << endl;
    BSTree p = read_file(dir+"p");
    cout << "average search time perfect "<< i << " "
	 << p.get_average_search_time() << endl;

    BSTree r = read_file(dir+"r");
    cout << "average search time random "<< i << " "
	 << r.get_average_search_time() << endl;


    if(i <= 4) {
      cout << "perfect tree " << i << endl << p;
      cout << "in order l" << i; l.inorder(cout); cout << endl;
      cout << "in order p" << i; p.inorder(cout); cout << endl;
      cout << "in order r" << i; r.inorder(cout); cout << endl;
    }

    ofstream Lfile;
    Lfile.open("[l" + to_string(i) + "].txt");
    l.inorder(Lfile);
    Lfile.close();
    ofstream Pfile;
    Pfile.open("[p" + to_string(i) + "].txt");
    p.inorder(Pfile);
    Pfile.close();
    ofstream Rfile;
    Rfile.open("[r" + to_string(i) + "].txt");
    l.inorder(Rfile);
    Rfile.close();

    cout << endl;
  }
    
}

