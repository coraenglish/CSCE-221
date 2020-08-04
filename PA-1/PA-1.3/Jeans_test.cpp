#include "Collection.h"
#include "Jeans.h"
#include <iostream>
#include <fstream>

using namespace std;
using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;


// input operator (reading from a file):
//reads from the istream is pairs in this format: color size (no parentheses or colons, use space to separate
//them). As colors use strings (you can use STL class string here): white, blue, brown, black, and as sizes
//use strings: small, medium, large. You need to read from an input file where each pair is in one line. Use
//at least two input files: Obj1.data and Obj2.data for two collections.
istream& operator>>(istream& is, CollectionJN& coll) {
    string color;
    string size;
    Jeans_colors c;
    Jeans_sizes s;
    
    is >> color >> size;
    if (color == "white") {
        c = Jeans_colors::white;
    }  else if (color == "blue") {
        c = Jeans_colors::blue;
    } else if (color == "brown") {
        c = Jeans_colors::brown;
    } else if (color == "black") {
        c = Jeans_colors::black;
    }

    if (size == "small") {
        s = Jeans_sizes::small;
    }  else if (size == "medium") {
        s = Jeans_sizes::medium;
    } else if (size == "large") {
        s = Jeans_sizes::large;
    } else if (size == "xlarge") {
        s = Jeans_sizes::xlarge;
    }

    Jeans jn(c, s);

    coll.insert_item(jn);
    return is;
} 

void test_jeans() {

    // (b) Create two collection objects. Fill them with jeans: read jeans from a user input file. Use
    // between 10 and 15 jeans.
    
    CollectionJN jn_c1 = CollectionJN();

    ifstream ifs{"jeans1.data"};

    cout << "Reading in file 1..." << endl;
    while (!ifs.eof()) {
        ifs >> jn_c1;
    }

    cout << "Outputting collection jn_c1..." << endl;

    jn_c1.print_items();

    cout << "jn_c1 white: " << jn_c1.total_items(Jeans_colors::white) << endl;
    cout << "jn_c1 blue: " << jn_c1.total_items(Jeans_colors::blue) << endl;
    cout << "jn_c1 brown: " << jn_c1.total_items(Jeans_colors::brown) << endl;
    cout << "jn_c1 black: " << jn_c1.total_items(Jeans_colors::brown) << endl;
    cout << "jn_c1 small: " << jn_c1.total_items(Jeans_sizes::small) << endl;
    cout << "jn_c1 medium: " << jn_c1.total_items(Jeans_sizes::medium) << endl;
    cout << "jn_c1 large: " << jn_c1.total_items(Jeans_sizes::large) << endl;
    cout << "jn_c1 xlarge: " << jn_c1.total_items(Jeans_sizes::xlarge) << endl;
    cout << "jn_c1 total: " << jn_c1.total_items() << endl << endl;

    cout << "-----=======+++++++++=======-----" << endl << endl;


    CollectionJN jn_c2 = CollectionJN();

    ifstream ifs2{"jeans2.data"};

    cout << "Reading in file 2..." << endl;
    while (!ifs2.eof()) {
        ifs2 >> jn_c2;
    }

    cout << "Outputting collection jn_c2..." << endl;

    jn_c2.print_items();

    cout << "jn_c2 white: " << jn_c2.total_items(Jeans_colors::white) << endl;
    cout << "jn_c2 blue: " << jn_c2.total_items(Jeans_colors::blue) << endl;
    cout << "jn_c2 brown: " << jn_c2.total_items(Jeans_colors::brown) << endl;
    cout << "jn_c2 black: " << jn_c2.total_items(Jeans_colors::black) << endl;
    cout << "jn_c2 small: " << jn_c2.total_items(Jeans_sizes::small) << endl;
    cout << "jn_c2 medium: " << jn_c2.total_items(Jeans_sizes::medium) << endl;
    cout << "jn_c2 large: " << jn_c2.total_items(Jeans_sizes::large) << endl;
    cout << "jn_c2 xlarge: " << jn_c2.total_items(Jeans_sizes::xlarge) << endl;
    cout << "jn_c2 total: " << jn_c2.total_items() << endl << endl;

    cout << "-----=======+++++++++=======-----" << endl << endl;



    // (c) Sort and print out their contents: print out the number of jeans of a given color and the total amount
    // of jeans in the first and the second collection.
    
    
    sort_by_size(jn_c1, Sort_choice::bubble_sort);

    cout << "Outputting bubble sorted jn_c1..." << endl;

    jn_c1.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;

    sort_by_size(jn_c2, Sort_choice::insertion_sort);

    cout << "Outputting insertion sorted jn_c2..." << endl;

    jn_c2.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;

    
    
    // (d) Create a third collection which is the union of the two objects from (b). Print its elements. Print the number
    // of jeans of the same color and size. Print the total number of jeans.
    
    cout << "Joining files together..." << endl;

    CollectionJN jn_c3 = make_union(jn_c1, jn_c2);

    cout << "Outputting joined collection jn_c3" << endl;

    jn_c3.print_items();

    cout << "jn_c3 white: " << jn_c3.total_items(Jeans_colors::white) << endl;
    cout << "jn_c3 blue: " << jn_c3.total_items(Jeans_colors::blue) << endl;
    cout << "jn_c3 brown: " << jn_c3.total_items(Jeans_colors::brown) << endl;
    cout << "jn_c3 black: " << jn_c3.total_items(Jeans_colors::black) << endl;
    cout << "jn_c3 small: " << jn_c3.total_items(Jeans_sizes::small) << endl;
    cout << "jn_c3 medium: " << jn_c3.total_items(Jeans_sizes::medium) << endl;
    cout << "jn_c3 large: " << jn_c3.total_items(Jeans_sizes::large) << endl;
    cout << "jn_c3 xlarge: " << jn_c3.total_items(Jeans_sizes::xlarge) << endl;
    cout << "jn_c3 total: " << jn_c3.total_items() << endl << endl;

    cout << "-----=======+++++++++=======-----" << endl << endl;



    // (e) Swap two collections in (b). Print its elements to check if they correctly swapped.
    swap(jn_c1, jn_c2);

    cout << "Outputting swapped jn_c1..." << endl;

    jn_c1.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;

    cout << "Outputting swapped jn_c2..." << endl;

    jn_c2.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;


    // (f) Sort the first collection in (b). Print its elements to check if it is correctly sorted.
    
    sort_by_size(jn_c3, Sort_choice::selection_sort);

    cout << "Outputting selection sorted jn_c3..." << endl;

    jn_c3.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;

    // (g) You can do other tests not mentioned above in order to be sure that all you implemented functions are
    // correct.

    cout << "Removing small and 2 random jeans from jn_c3..." << endl;

    Jeans jn1(Jeans_colors::white, Jeans_sizes::small);
    Jeans jn2(Jeans_colors::blue, Jeans_sizes::small);
    Jeans jn3(Jeans_colors::black, Jeans_sizes::small);
    Jeans jn4(Jeans_colors::brown, Jeans_sizes::small);

    jn_c3.remove_this_item(jn1);
    jn_c3.remove_this_item(jn2);
    jn_c3.remove_this_item(jn3);
    jn_c3.remove_this_item(jn4);
    jn_c3.remove_any_item();
    jn_c3.remove_any_item();


    jn_c3.print_items();

    cout << "jn_c3 white: " << jn_c3.total_items(Jeans_colors::white) << endl;
    cout << "jn_c3 blue: " << jn_c3.total_items(Jeans_colors::blue) << endl;
    cout << "jn_c3 brown: " << jn_c3.total_items(Jeans_colors::brown) << endl;
    cout << "jn_c3 black: " << jn_c3.total_items(Jeans_colors::black) << endl;
    cout << "jn_c3 small: " << jn_c3.total_items(Jeans_sizes::small) << endl;
    cout << "jn_c3 medium: " << jn_c3.total_items(Jeans_sizes::medium) << endl;
    cout << "jn_c3 large: " << jn_c3.total_items(Jeans_sizes::large) << endl;
    cout << "jn_c3 xlarge: " << jn_c3.total_items(Jeans_sizes::xlarge) << endl;
    cout << "jn_c3 total: " << jn_c3.total_items() << endl << endl;

    cout << "-----=======+++++++++=======-----" << endl << endl;

}