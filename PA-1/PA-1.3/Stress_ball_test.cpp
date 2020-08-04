#include "Collection.h"
#include "Stress_ball.h"
#include <iostream>
#include <fstream>

using namespace std;
using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;

// input operator (reading from a file):
//reads from the istream is pairs in this format: color size (no parentheses or colons, use space to separate
//them). As colors use strings (you can use STL class string here): red, blue, yellow, green, and as sizes
//use strings: small, medium, large. You need to read from an input file where each pair is in one line. Use
//at least two input files: Obj1.data and Obj2.data for two collections.
istream& operator>>(istream& is, CollectionSB& coll) {
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

void test_stress_balls() {

    // (b) Create two collection objects. Fill them with stress balls: read stress balls from a user input file. Use
    // between 10 and 15 stress balls.
    
    CollectionSB sb_c1 = CollectionSB();

    ifstream ifs{"stress_ball1.data"};

    cout << "Reading in file 1..." << endl;
    while (!ifs.eof()) {
        ifs >> sb_c1;
    }

    cout << "Outputting collection sb_c1..." << endl;

    sb_c1.print_items();

    cout << "sb_c1 red: " << sb_c1.total_items(Stress_ball_colors::red) << endl;
    cout << "sb_c1 blue: " << sb_c1.total_items(Stress_ball_colors::blue) << endl;
    cout << "sb_c1 yellow: " << sb_c1.total_items(Stress_ball_colors::yellow) << endl;
    cout << "sb_c1 green: " << sb_c1.total_items(Stress_ball_colors::green) << endl;
    cout << "sb_c1 small: " << sb_c1.total_items(Stress_ball_sizes::small) << endl;
    cout << "sb_c1 medium: " << sb_c1.total_items(Stress_ball_sizes::medium) << endl;
    cout << "sb_c1 large: " << sb_c1.total_items(Stress_ball_sizes::large) << endl;
    cout << "sb_c1 total: " << sb_c1.total_items() << endl << endl;

    cout << "-----=======+++++++++=======-----" << endl << endl;


    CollectionSB sb_c2 = CollectionSB();

    ifstream ifs2{"stress_ball2.data"};

    cout << "Reading in file 2..." << endl;
    while (!ifs2.eof()) {
        ifs2 >> sb_c2;
    }

    cout << "Outputting collection sb_c2..." << endl;

    sb_c2.print_items();

    cout << "sb_c2 red: " << sb_c2.total_items(Stress_ball_colors::red) << endl;
    cout << "sb_c2 blue: " << sb_c2.total_items(Stress_ball_colors::blue) << endl;
    cout << "sb_c2 yellow: " << sb_c2.total_items(Stress_ball_colors::yellow) << endl;
    cout << "sb_c2 green: " << sb_c2.total_items(Stress_ball_colors::green) << endl;
    cout << "sb_c2 small: " << sb_c2.total_items(Stress_ball_sizes::small) << endl;
    cout << "sb_c2 medium: " << sb_c2.total_items(Stress_ball_sizes::medium) << endl;
    cout << "sb_c2 large: " << sb_c2.total_items(Stress_ball_sizes::large) << endl;
    cout << "sb_c2 total: " << sb_c2.total_items() << endl << endl;

    cout << "-----=======+++++++++=======-----" << endl << endl;



    // (c) Sort and print out their contents: print out the number of stress balls of a given color and the total amount
    // of stress balls in the first and the second collection.
    
    
    sort_by_size(sb_c1, Sort_choice::bubble_sort);

    cout << "Outputting bubble sorted sb_c1..." << endl;

    sb_c1.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;

    sort_by_size(sb_c2, Sort_choice::insertion_sort);

    cout << "Outputting insertion sorted sb_c2..." << endl;

    sb_c2.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;

    
    
    // (d) Create a third collection which is the union of the two objects from (b). Print its elements. Print the number
    // of stress balls of the same color and size. Print the total number of stress balls.
    
    cout << "Joining files together..." << endl;

    CollectionSB sb_c3 = make_union(sb_c1, sb_c2);

    cout << "Outputting joined collection sb_c3" << endl;

    sb_c3.print_items();

    cout << "sb_c3 red: " << sb_c3.total_items(Stress_ball_colors::red) << endl;
    cout << "sb_c3 blue: " << sb_c3.total_items(Stress_ball_colors::blue) << endl;
    cout << "sb_c3 yellow: " << sb_c3.total_items(Stress_ball_colors::yellow) << endl;
    cout << "sb_c3 green: " << sb_c3.total_items(Stress_ball_colors::green) << endl;
    cout << "sb_c3 small: " << sb_c3.total_items(Stress_ball_sizes::small) << endl;
    cout << "sb_c3 medium: " << sb_c3.total_items(Stress_ball_sizes::medium) << endl;
    cout << "sb_c3 large: " << sb_c3.total_items(Stress_ball_sizes::large) << endl;
    cout << "sb_c3 total: " << sb_c3.total_items() << endl << endl;

    cout << "-----=======+++++++++=======-----" << endl << endl;



    // (e) Swap two collections in (b). Print its elements to check if they correctly swapped.
    swap(sb_c1, sb_c2);

    cout << "Outputting swapped sb_c1..." << endl;

    sb_c1.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;

    cout << "Outputting swapped sb_c2..." << endl;

    sb_c2.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;


    // (f) Sort the first collection in (b). Print its elements to check if it is correctly sorted.
    
    sort_by_size(sb_c3, Sort_choice::selection_sort);

    cout << "Outputting selection sorted sb_c3..." << endl;

    sb_c3.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;

    // (g) You can do other tests not mentioned above in order to be sure that all you implemented functions are
    // correct.

    cout << "Removing small and 2 random stress balls from sb_c3..." << endl;

    Stress_ball sb1(Stress_ball_colors::red, Stress_ball_sizes::small);
    Stress_ball sb2(Stress_ball_colors::blue, Stress_ball_sizes::small);
    Stress_ball sb3(Stress_ball_colors::green, Stress_ball_sizes::small);
    Stress_ball sb4(Stress_ball_colors::yellow, Stress_ball_sizes::small);

    sb_c3.remove_this_item(sb1);
    sb_c3.remove_this_item(sb2);
    sb_c3.remove_this_item(sb3);
    sb_c3.remove_this_item(sb4);
    sb_c3.remove_any_item();
    sb_c3.remove_any_item();


    sb_c3.print_items();

    cout << "sb_c3 red: " << sb_c3.total_items(Stress_ball_colors::red) << endl;
    cout << "sb_c3 blue: " << sb_c3.total_items(Stress_ball_colors::blue) << endl;
    cout << "sb_c3 yellow: " << sb_c3.total_items(Stress_ball_colors::yellow) << endl;
    cout << "sb_c3 green: " << sb_c3.total_items(Stress_ball_colors::green) << endl;
    cout << "sb_c3 small: " << sb_c3.total_items(Stress_ball_sizes::small) << endl;
    cout << "sb_c3 medium: " << sb_c3.total_items(Stress_ball_sizes::medium) << endl;
    cout << "sb_c3 large: " << sb_c3.total_items(Stress_ball_sizes::large) << endl;
    cout << "sb_c3 total: " << sb_c3.total_items() << endl << endl;

    cout << "-----=======+++++++++=======-----" << endl << endl;

}