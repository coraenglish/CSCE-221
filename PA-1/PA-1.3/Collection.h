#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include <random>
#include <string>

using namespace std;

template <class Obj, class F1, class F2>
class Collection {
private:
    Obj *array; //pointer to dynamically allocated memory
    int size; //logical size of array - the number of elements in use
    int capacity; //physical size of array
    // Note that size <= capacity.
    void resize();

public:
    Collection(); 
    Collection(int collection_size); 
    Collection(const Collection<Obj, F1, F2>& rhs); 
    Collection<Obj, F1, F2>& operator=(const Collection<Obj, F1, F2>& rhs);
    ~Collection(); 

     
    Collection(Collection<Obj, F1, F2> && );// move constructor – efficiently creates a new collection from an existing one
    Collection<Obj, F1, F2>& operator=(Collection<Obj, F1, F2> &&); // move assignment – efficiently copies a collection during an assignment
    
    void insert_item(const Obj& sb);

    bool contains(const Obj& sb) const;
        
    
    Obj remove_any_item(); 

    void remove_this_item(const Obj& sb); 

    void make_empty(); 
        
    bool is_empty() const; 
        
    int total_items() const; 
        
    int total_items(F2 s) const; 
        
    int total_items(F1 t) const; 
        
    void print_items() const; 

    Obj& operator[](int i);

    const Obj& operator[](int i) const;
};




template <class Obj, class F1, class F2>
ostream& operator<<(ostream& os, const Collection<Obj, F1, F2>& c); 

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2>& c1, const Collection<Obj, F1, F2>& c2); 

template <class Obj, class F1, class F2>
void swap(Collection<Obj, F1, F2>& c1, Collection<Obj, F1, F2>& c2); 

enum class Sort_choice { bubble_sort, insertion_sort, selection_sort };

template <class Obj, class F1, class F2>
void sort_by_size(Collection<Obj, F1, F2>& c, Sort_choice sort); 


// constructor with no arguments, size and capacity are 0, and array is nullptr.
template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::Collection(): array(nullptr), size(0), capacity(0) {} 


// constructor with one argument which is the required size of the collection
template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::Collection(int collection_size) {
    size = collection_size;
    capacity = collection_size;
    array = new Obj[collection_size];
} 


// copy constructor – makes a copy of a collection
template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::Collection(Collection const& rhs): array(nullptr), size(rhs.size), capacity(rhs.capacity) {
    array = new Obj[capacity];
    for (int i = 0; i < size; ++i) {
        array[i] = rhs.array[i];
    }
} 


// copy assignment – overwrites an exiting collection by another collection
template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>& Collection<Obj, F1, F2>::operator=(const Collection& rhs) {
    if (this == &rhs) {
        return *this;
    }

    make_empty();
    size = rhs.size;
    capacity = rhs.capacity;
    array = new Obj[capacity];

    for (int i = 0; i < rhs.size; ++i) {
        array[i] = rhs.array[i];
    }
    return *this;
}


// destructor – destroys a collection (deallocates allocated memory, set to zero size and capacity)
template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::~Collection() {
    make_empty();
} 


// move constructor – efficiently creates a new collection from an existing one
template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::Collection(Collection && c) : array(c.array), size(c.size), capacity(c.capacity) {
    c.array = nullptr;
    c.size = 0;
    c.capacity = 0;    
}

// move assignment – efficiently copies a collection during an assignment
template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>& Collection<Obj, F1, F2>::operator=(Collection && c) {
    make_empty(); //deallocate old space
    array = c.array; //copy array
    size = c.size; //copy size
    c.array = nullptr;
    c.size = 0;
    return *this;
} 



//resize function doubles capacity of array
template <class Obj, class F1, class F2>
void Collection<Obj, F1, F2>::resize() {
    if (size == 0) {
       size = 0;
       capacity = 1;
       array = new Obj[capacity];
       return;
    }

    int new_capacity = capacity*2;
    Obj* new_array = new Obj[new_capacity];

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
template <class Obj, class F1, class F2>
void Collection<Obj, F1, F2>::insert_item(const Obj& sb) {
    if (size == capacity) {
        resize();
    }
    array[size] = sb;
    size++;
} 


//check if a stress ball of a given color and size is in the collection; return true if it is there and false otherwise:
template <class Obj, class F1, class F2>
bool Collection<Obj, F1, F2>::contains(const Obj& sb) const {
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
template <class Obj, class F1, class F2>
Obj Collection<Obj, F1, F2>::remove_any_item() {
    if (size == 0) {
        throw;
    } else {
        srand(time(NULL));
        int random_idx = rand() % size;
        Obj random_sb = array[random_idx];

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
template <class Obj, class F1, class F2>
void Collection<Obj, F1, F2>::remove_this_item(const Obj& sb) {
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
template <class Obj, class F1, class F2>
void Collection<Obj, F1, F2>::make_empty() {
    if (array != nullptr) {
        delete [] array;
        array = nullptr;
    }
    size = 0;
    capacity = 0;
} 
    

// check if the collection is empty; return true if it is empty and false otherwise:
template <class Obj, class F1, class F2>
bool Collection<Obj, F1, F2>::is_empty() const {
    if (size == 0 && capacity == 0 && array == nullptr) {
        return true;
    }
    return false;
} 
    

// return the total number of stress balls in the collection:
template <class Obj, class F1, class F2>
int Collection<Obj, F1, F2>::total_items() const {
    return size;
} 


// return the number of stress balls of the same size in the collection:
template <class Obj, class F1, class F2>
int Collection<Obj, F1, F2>::total_items(F2 s) const {
    int same_size = 0;
    for (int i = 0; i < size; ++i) {
        if (static_cast<int>(array[i].get_size()) == static_cast<int>(s)) same_size++;
    }

    return same_size;
} 
    

// return the number of stress balls of the same color in the collection:
template <class Obj, class F1, class F2>
int Collection<Obj, F1, F2>::total_items(F1 t) const {
    int same_color = 0;
    for (int i = 0; i < size; ++i) {
        if (static_cast<int>(array[i].get_color()) == static_cast<int>(t)) same_color++;
    }

    return same_color;
} 


// print all the stress balls in the collection (print color and size of a stress ball, see the class Obj):
template <class Obj, class F1, class F2>
void Collection<Obj, F1, F2>::print_items() const {
    for (int i = 0; i < size; ++i) {
        cout << array[i];
    }
} 


//To directly access a stress ball in a collection, overload operator[]. It will access a stress ball in
//array at position i where i starts from 0 through size-1:
template <class Obj, class F1, class F2>
Obj& Collection<Obj, F1, F2>::operator[](int i) {
    return array[i];
}


//To directly access a stress ball in a const collection, overload operator[]. It will have the exact same
//body as the above overload, but the function header should read:
template <class Obj, class F1, class F2>
const Obj& Collection<Obj, F1, F2>::operator[](int i) const {    
    return array[i];
}



// ==================================================================== //






// output operator:
// prints to the ostream os all the collection items in format: (color, size), each in one line. Use cout as
// output but you can use an output file either.
template <class Obj, class F1, class F2>
ostream& operator <<(ostream& os, const Collection<Obj, F1, F2>& c) {
    for (int i = 0; i < c.total_items(); ++i) {
        os << c[i] << endl;
    }
    return os;
} 


//union operation that combines the contents of two collections into a third collection (the contents of c1
//and c2 are not changed)
template <class Obj, class F1, class F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2>& c1, const Collection<Obj, F1, F2>& c2) {
    Collection<Obj, F1, F2> c3 = Collection<Obj, F1, F2>();
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
template <class Obj, class F1, class F2>
void swap(Collection<Obj, F1, F2>& c1, Collection<Obj, F1, F2>& c2) {
    Collection<Obj, F1, F2> temp(move(c1));
    c1 = move(c2);
    c2 = move(temp);
} 


// A sort function that sorts the collection with respect to the size of its elements (small < medium <large):
// Then elements will be sorted with respect to their size in array (we do not sort them with respect to
// color). You need to implement 3 different sorting algorithms (do not use the STL sort): bubble sort,
// quick sort, and merge sort. Here is the enum class Sort_choice:
// Use switch statement to choose the required one. You need to test all three sort functions.
template <class Obj, class F1, class F2>
void sort_by_size(Collection<Obj, F1, F2>& c, Sort_choice sort) {
    switch (sort) {
    case Sort_choice::bubble_sort:
        
        for (int i = 0; i < c.total_items() - 1; ++i) {
            for (int j = 0; j < c.total_items() - i - 1; ++j) {
                if (c[j].get_size() > c[j+1].get_size()) {
                    Obj temp = c[j+1];
                    c[j+1] = c[j];
                    c[j] = temp;
                }
            }
        }
        break;
    
    case Sort_choice::insertion_sort:

        for (int i = 1; i < c.total_items(); i++) {  
            Obj temp = c[i];  
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
                    Obj temp = c[i];
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



#endif
