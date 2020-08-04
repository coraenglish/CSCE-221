#include "Stress_ball.h"
#include "Collection.h"
#include "Stress_ball_colors.h"
#include "Stress_ball_sizes.h"
#include <iostream>

#include <random>
#include <string>

using namespace std;

// constructor with no arguments, size and capacity are 0, and array is nullptr.
Collection::Collection(): array(nullptr), size(0), capacity(0) {} 


// constructor with one argument which is the required size of the collection
Collection::Collection(int collection_size) {
    size = collection_size;
    capacity = collection_size;
    array = new Stress_ball[collection_size];
} 


// copy constructor – makes a copy of a collection
Collection::Collection(Collection const& rhs): array(nullptr), size(rhs.size), capacity(rhs.capacity) {
    array = new Stress_ball[capacity];
    for (int i = 0; i < size; ++i) {
        array[i] = rhs.array[i];
    }
} 


// copy assignment – overwrites an exiting collection by another collection
Collection& Collection::operator=(const Collection& rhs) {
    if (this == &rhs) {
        return *this;
    }

    make_empty();
    size = rhs.size;
    capacity = rhs.capacity;
    array = new Stress_ball[capacity];

    for (int i = 0; i < rhs.size; ++i) {
        array[i] = rhs.array[i];
    }
    return *this;
}


// destructor – destroys a collection (deallocates allocated memory, set to zero size and capacity)
Collection::~Collection() {
    make_empty();
} 


// move constructor – efficiently creates a new collection from an existing one
Collection::Collection(Collection && c) : array(c.array), size(c.size), capacity(c.capacity) {
    c.array = nullptr;
    c.size = 0;
    c.capacity = 0;    
}

// move assignment – efficiently copies a collection during an assignment
Collection& Collection::operator=(Collection && c) {
    make_empty(); //deallocate old space
    array = c.array; //copy array
    size = c.size; //copy size
    c.array = nullptr;
    c.size = 0;
    return *this;
} 



//resize function doubles capacity of array
void Collection::resize() {
    if (size == 0) {
       size = 0;
       capacity = 1;
       array = new Stress_ball[capacity];
       return;
    }

    int new_capacity = capacity*2;
    Stress_ball* new_array = new Stress_ball[new_capacity];

    for (int i = 0; i < size; ++i) {
        new_array[i] = array[i];
    }

    capacity = new_capacity;
    delete [] array;
    array = new_array;

}

//insert a stress ball to the collection 
// If the collection is full, increase the array by doubling its size. Use the private helper function
// resize() to complete this task. The function resize() should double the size of the array and
// correctly copy elements from the old array to a new array.
void Collection::insert_item(const Stress_ball& sb) {
    if (size == capacity) {
        resize();
    }
    array[size] = sb;
    size++;
} 


//check if a stress ball of a given color and size is in the collection; return true if it is there and false otherwise:
bool Collection::contains(const Stress_ball& sb) const {
    for (int i = 0; i < size; ++i) {
        if (array[i] == sb) {
            return true;
        }
    }
    return false;
} 
    

//remove and return a random stress ball (you have no control which stress ball is selected)        
// Do not decrease the size of the array. Also, be sure that there are no gaps between elements of the
// array. Throw an exception if the collection is already empty.
Stress_ball Collection::remove_any_item() {
    if (size == 0) {
        throw;
    } else {
        srand(time(NULL));
        int random_idx = rand() % size;
        Stress_ball random_sb = array[random_idx];

        for (int i = random_idx; i < size-1; ++i) {
            array[i] = array[i+1];
        }
        size--;       
        return random_sb;
    }
} 


// remove a stress ball with a specific color and size from the collection
// Do not decrease the size of the array. Also, be sure that there are no gaps between elements of the
// array. Throw an exception if the collection is already empty.
void Collection::remove_this_item(const Stress_ball& sb) {
    if (size == 0) {
        throw;
    } else {
        int found_idx = size;
        for (int i = 0; i < size; ++i) {
            if (array[i] == sb) {
                int found_idx = i;
                for (int j = found_idx; j < size-1; ++j) {
                    array[j] = array[j+1];
                }
                size--;
                break;
            }
        }

    }
    
} 


// make the collection empty (deallocate allocated memory, set to zero size and capacity):
void Collection::make_empty() {
    if (array != nullptr) {
        delete [] array;
        array = nullptr;
    }
    size = 0;
    capacity = 0;
} 
    

// check if the collection is empty; return true if it is empty and false otherwise:
bool Collection::is_empty() const {
    if (size == 0 && capacity == 0 && array == nullptr) {
        return true;
    }
    return false;
} 
    

// return the total number of stress balls in the collection:
int Collection::total_items() const {
    return size;
} 


// return the number of stress balls of the same size in the collection:
int Collection::total_items(Stress_ball_sizes s) const {
    int same_size = 0;
    for (int i = 0; i < size; ++i) {
        if (static_cast<int>(array[i].get_size()) == static_cast<int>(s)) same_size++;
    }

    return same_size;
} 
    

// return the number of stress balls of the same color in the collection:
int Collection::total_items(Stress_ball_colors t) const {
    int same_color = 0;
    for (int i = 0; i < size; ++i) {
        if (static_cast<int>(array[i].get_color()) == static_cast<int>(t)) same_color++;
    }

    return same_color;
} 


// print all the stress balls in the collection (print color and size of a stress ball, see the class Stress_ball):
void Collection::print_items() const {
    for (int i = 0; i < size; ++i) {
        cout << array[i];
    }
} 


//To directly access a stress ball in a collection, overload operator[]. It will access a stress ball in
//array at position i where i starts from 0 through size-1:
Stress_ball& Collection::operator[](int i) {
    return array[i];
}


//To directly access a stress ball in a const collection, overload operator[]. It will have the exact same
//body as the above overload, but the function header should read:
const Stress_ball& Collection::operator[](int i) const {    
    return array[i];
}



// ==================================================================== //



// input operator (reading from a file):
//reads from the istream is pairs in this format: color size (no parentheses or colons, use space to separate
//them). As colors use strings (you can use STL class string here): red, blue, yellow, green, and as sizes
//use strings: small, medium, large. You need to read from an input file where each pair is in one line. Use
//at least two input files: stress_ball1.data and stress_ball2.data for two collections.
istream& operator>>(istream& is, Collection& coll) {
    string color;
    string size;
    Stress_ball_colors c;
    Stress_ball_sizes s;
    
    is >> color >> size;
    if (color == "red") {
        c = Stress_ball_colors::red;
    }  else if (color == "blue") {
        c = Stress_ball_colors::blue;
    } else if (color == "yellow") {
        c = Stress_ball_colors::yellow;
    } else if (color == "green") {
        c = Stress_ball_colors::green;
    }

    if (size == "small") {
        s = Stress_ball_sizes::small;
    }  else if (size == "medium") {
        s = Stress_ball_sizes::medium;
    } else if (size == "large") {
        s = Stress_ball_sizes::large;
    } 

    Stress_ball sb(c, s);

    coll.insert_item(sb);
    return is;
} 


// output operator:
// prints to the ostream os all the collection items in format: (color, size), each in one line. Use cout as
// output but you can use an output file either.
ostream& operator <<(ostream& os, const Collection& c) {
    for (int i = 0; i < c.total_items(); ++i) {
        os << c[i] << endl;
    }
    return os;
} 


//union operation that combines the contents of two collections into a third collection (the contents of c1
//and c2 are not changed)
Collection make_union(const Collection& c1, const Collection& c2) {
    Collection c3 = Collection();
    for (int i = 0; i < c1.total_items(); ++i) {
        c3.insert_item(c1[i]);
    }
    for (int j = 0; j < c2.total_items(); ++j) {
        c3.insert_item(c2[j]);
    }
    return c3;
} 


// a swap operation that swaps two collections:
// Use the move constructor and move assignment to do this. Do not copy the collection elements.
void swap(Collection& c1, Collection& c2) {
    Collection temp(move(c1));
    c1 = move(c2);
    c2 = move(temp);
} 


// A sort function that sorts the collection with respect to the size of its elements (small < medium <large):
// Then elements will be sorted with respect to their size in array (we do not sort them with respect to
// color). You need to implement 3 different sorting algorithms (do not use the STL sort): bubble sort,
// quick sort, and merge sort. Here is the enum class Sort_choice:
// Use switch statement to choose the required one. You need to test all three sort functions.
void sort_by_size(Collection& c, Sort_choice sort) {
    switch (sort) {
    case Sort_choice::bubble_sort:
        
        for (int i = 0; i < c.total_items() - 1; ++i) {
            for (int j = 0; j < c.total_items() - i - 1; ++j) {
                if (c[j].get_size() > c[j+1].get_size()) {
                    Stress_ball temp = c[j+1];
                    c[j+1] = c[j];
                    c[j] = temp;
                }
            }
        }
        break;
    
    case Sort_choice::insertion_sort:

        for (int i = 1; i < c.total_items(); i++) {  
            Stress_ball temp = c[i];  
            int j = i - 1;  
            while (j >= 0 && c[j].get_size() > temp.get_size()) {  
                c[j + 1] = c[j];  
                j = j - 1;  
            }  
            c[j + 1] = temp;  
        }  
        break;

    case Sort_choice::selection_sort:

        int i = 0;
        while (i < c.total_items()-1) {
            int min_idx = i;
            int j = i + 1;
            while (j < c.total_items()) {
                if (c[j].get_size() < c[min_idx].get_size()) {
                    min_idx = j;
                    Stress_ball temp = c[i];
                    c[i] = c[min_idx];
                    c[min_idx] = temp;
                }
                j++;
            }
            i++;
        }
        break;
    
    }
} 

