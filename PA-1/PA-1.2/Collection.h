#ifndef COLLECTION_H
#define COLLECTION_H
#include "Stress_ball.h"
#include <iostream>

using namespace std;

class Collection {
private:
    Stress_ball *array; //pointer to dynamically allocated memory
    int size; //logical size of array - the number of elements in use
    int capacity; //physical size of array
    // Note that size <= capacity.
    void resize();

public:
    Collection(/* args */); 
    Collection(int collection_size); 
    Collection(const Collection& rhs); 
    Collection& operator=(const Collection& rhs);
    ~Collection(); 

     
    Collection(Collection && );// move constructor – efficiently creates a new collection from an existing one
    Collection& operator=(Collection &&); // move assignment – efficiently copies a collection during an assignment
    
    void insert_item(const Stress_ball& sb); 

    bool contains(const Stress_ball& sb) const; 
        
    
    Stress_ball remove_any_item(); 

    void remove_this_item(const Stress_ball& sb); 

    void make_empty(); 
        
    bool is_empty() const; 
        
    int total_items() const; 
        
    int total_items(Stress_ball_sizes s) const; 
        
    int total_items(Stress_ball_colors t) const; 
        
    void print_items() const; 

    Stress_ball& operator[](int i);

    const Stress_ball& operator[](int i) const;
};




istream& operator>>(istream& is, Collection& c); 
ostream& operator<<(ostream& os, const Collection& c); 

Collection make_union(const Collection& c1, const Collection& c2); 

void swap(Collection& c1, Collection& c2); 

enum class Sort_choice { bubble_sort, insertion_sort, selection_sort };

void sort_by_size(Collection& c, Sort_choice sort); 


#endif
