// #ifndef BSTREE_CPP
// #define BSTREE_CPP

#include "BSTree.h"
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

// input / output operators
ostream& operator<<(ostream& out, BSTree& tree)
{
  tree.print_level_by_level(out);
  return out;
}

ostream& operator<<(ostream& out, Node node)
{
  if (&node == nullptr) return out << "NOT FOUND"; 
  return out << "( " << node.value << ", "
	     << node.search_time << " )";
}

istream& operator>>(istream& in, BSTree& tree)
{ 
  int next;
  while(in >> next) 
    tree.insert(next);
  return in;
}

///////////// Implementation To Do ////////////////////

// copy constructor
BSTree::BSTree(const BSTree& other)
{
  /*
    complete this copy constructor
    make sure when copying nodes to copy
    the value and left and right children
  */
  size = other.size;
  root = new Node(other.root->value);
  copy_helper(root, other.root);

}

// move constructor
BSTree::BSTree(BSTree&& other) : root(other.root)
{
  other.root = nullptr;
}

//copy assignment
BSTree& BSTree::operator=(const BSTree& other)
{
  /*
    complete this assignment operator
    make sure when copying nodes to copy
    the value and left and right children
    not important for this part but will be used later
  */
  size = 0;
  if (this != &other) {
    delete_helper(this->root);
    size = other.size;
    root = new Node(other.root->value);
    copy_helper(root, other.root);
  }
  return *this;
}

// move assignment
BSTree BSTree::operator=(BSTree&& other)
{ 
  Node* temp = root;
  root = other.root;
  other.root = temp;
  return *this;
}

// destructor
BSTree::~BSTree()
{
  delete_helper(root);
}

void BSTree::delete_helper(Node* n) 
{
  if (n) {
    delete_helper(n->left);
    delete_helper(n->right);
    delete n;
  }
}

// recursive
void BSTree::copy_helper(Node* copy_to, const Node* copy_from) const
{
  if(copy_from == nullptr)
    return;

  if(copy_from->left != nullptr) {
    copy_to->left = new Node(*copy_from->left);
    copy_helper(copy_to->left, copy_from->left);
  } else {
    copy_to->left = nullptr;
  }

  if(copy_from->right != nullptr) {
    copy_to->right = new Node(*copy_from->right);
    copy_helper(copy_to->right, copy_from->right);
  } else {
    copy_to->right = nullptr;
  }
}

Node* BSTree::insert_helper(int x, Node* n, int search_cost) 
{
  if (n==nullptr) 
  {
    n = new Node(x);
    n->search_time = search_cost;
  } 
  else if (x < n->value) 
  {
    search_cost++;
    n->left = insert_helper(x, n->left, search_cost);
  } 
  else if (x > n->value) 
  {
    search_cost++;
    n->right = insert_helper(x, n->right, search_cost);
  } 
  else 
  {
    cout << "Duplicate" << endl;
    exit(-1);
  }
  return n;
}


Node* BSTree::insert(int obj)
{
  /*
    insert a node into the tree
    first find where the node should go
    then modify pointers to connect your new node 
  */
  size++;
  if (root == nullptr) {
    root = new Node(obj);
    root->search_time = 1;
    return root;
  }
  int search_cost=1;
  return insert_helper(obj, root, search_cost);
}


Node* BSTree::search(int obj)
{
  /*
    recursivly search down the tree to find the node that contains obj
    if you dont find anything return null
  */
  Node* n = root;
  while (n) {
    if (obj < n->value) n = n->left;
    else if (obj > n->value) n = n->right;
    else return n;
  }
  return nullptr;
}

// I already implemented updating search times in the insert helper function, so this is here just because we had to write it.
void BSTree::update_search_times()
{
  /*
    do a BFS or DFS of your tree and update the searchtimes of all nodes
  */
  queue<Node*> q;

  q.push(root);
  int search_cost = 1;
  root->search_time = search_cost;

  while (!q.empty()) {
    Node* node = q.front();
    search_cost++;
    q.pop();
    if (node->left != NULL) {
      node->search_time = search_cost;
      q.push(node->left);
    }

    if (node->right != NULL) {
      node->search_time = search_cost;
      q.push(node->right);
    }
  }
}

ostream& BSTree::inorder_helper(Node* n, ostream& out) 
{
  if (n==nullptr) {
    return out;
  }

  inorder_helper(n->left, out);

  out << n->value << "["<<n->search_time<<"] ";

  inorder_helper(n->right, out);
}

ostream& BSTree::inorder(ostream& out)
{
  return inorder_helper(root, out);
}

// implemented
void BSTree::pretty_print_node(ostream& out, Node* node)
{
  out << node->value << "["<<node->search_time<<"] ";
}

// implemented
ostream& BSTree::print_level_by_level(ostream& out)
{
  /*
    print the tree using a BFS 
    output should look like this if we dont have a full tree

    4
    2 6
    1 X 5 7
    X X X X X X X 9

    it will be helpfull to do this part iterativly, 
    so do the BFS with the std stack data structure.

    it may also be helpfull to put the entire tree into a vector 
    (probably google this if you dont know how to do it)
  */

  if(root == nullptr)
    return out;

  bool hasNodes = true;
  vector<Node*> current_level;
  vector<Node*> next_level;
  current_level.push_back(root);
  while(hasNodes) {
    hasNodes = false;
    for(auto node : current_level) {
      if(node != nullptr) {
	pretty_print_node(out, node);
	if(node->left != nullptr)
	  hasNodes = true;
	if(node->right != nullptr)
	  hasNodes = true;
	
	next_level.push_back(node->left);
	next_level.push_back(node->right);
      } else {
	out << "X ";
	next_level.push_back(nullptr);
	next_level.push_back(nullptr);
      }
    }
    out << endl;
    current_level.clear();
    current_level = next_level;
    next_level.clear();
  }

  return out;
}

// implemented
int BSTree::get_total_search_time(Node* node)
{
  if(node == nullptr)
    return 0;

  return get_total_search_time(node->left) +
    get_total_search_time(node->right) + node->search_time;
}

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if(total_search_time == 0)
    return -1;

  return ((float)total_search_time)/size;
}

// #endif
