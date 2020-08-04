#include "Collection.h"
#include "Stress_ball.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    // (b) Create two collection objects. Fill them with stress balls: read stress balls from a user input file. Use
    // between 10 and 15 stress balls.
    
    Collection c1 = Collection();

    ifstream ifs{"stress_ball1.data"};

    cout << "Reading in file 1..." << endl;
    while (!ifs.eof()) {
        ifs >> c1;
    }

    cout << "Outputting collection c1..." << endl;

    c1.print_items();

    cout << "c1 red: " << c1.total_items(Stress_ball_colors::red) << endl;
    cout << "c1 blue: " << c1.total_items(Stress_ball_colors::blue) << endl;
    cout << "c1 yellow: " << c1.total_items(Stress_ball_colors::yellow) << endl;
    cout << "c1 green: " << c1.total_items(Stress_ball_colors::green) << endl;
    cout << "c1 small: " << c1.total_items(Stress_ball_sizes::small) << endl;
    cout << "c1 medium: " << c1.total_items(Stress_ball_sizes::medium) << endl;
    cout << "c1 large: " << c1.total_items(Stress_ball_sizes::large) << endl;
    cout << "c1 total: " << c1.total_items() << endl << endl;

    cout << "-----=======+++++++++=======-----" << endl << endl;


    Collection c2 = Collection();

    ifstream ifs2{"stress_ball2.data"};

    cout << "Reading in file 2..." << endl;
    while (!ifs2.eof()) {
        ifs2 >> c2;
    }

    cout << "Outputting collection c2..." << endl;

    c2.print_items();

    cout << "c2 red: " << c2.total_items(Stress_ball_colors::red) << endl;
    cout << "c2 blue: " << c2.total_items(Stress_ball_colors::blue) << endl;
    cout << "c2 yellow: " << c2.total_items(Stress_ball_colors::yellow) << endl;
    cout << "c2 green: " << c2.total_items(Stress_ball_colors::green) << endl;
    cout << "c2 small: " << c2.total_items(Stress_ball_sizes::small) << endl;
    cout << "c2 medium: " << c2.total_items(Stress_ball_sizes::medium) << endl;
    cout << "c2 large: " << c2.total_items(Stress_ball_sizes::large) << endl;
    cout << "c2 total: " << c2.total_items() << endl << endl;

    cout << "-----=======+++++++++=======-----" << endl << endl;



    // (c) Sort and print out their contents: print out the number of stress balls of a given color and the total amount
    // of stress balls in the first and the second collection.
    
    
    sort_by_size(c1, Sort_choice::bubble_sort);

    cout << "Outputting bubble sorted c1..." << endl;

    c1.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;

    sort_by_size(c2, Sort_choice::insertion_sort);

    cout << "Outputting insertion sorted c2..." << endl;

    c2.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;

    
    
    // (d) Create a third collection which is the union of the two objects from (b). Print its elements. Print the number
    // of stress balls of the same color and size. Print the total number of stress balls.
    
    cout << "Joining files together..." << endl;

    Collection c3 = make_union(c1, c2);

    cout << "Outputting joined collection c3" << endl;

    c3.print_items();

    cout << "c3 red: " << c3.total_items(Stress_ball_colors::red) << endl;
    cout << "c3 blue: " << c3.total_items(Stress_ball_colors::blue) << endl;
    cout << "c3 yellow: " << c3.total_items(Stress_ball_colors::yellow) << endl;
    cout << "c3 green: " << c3.total_items(Stress_ball_colors::green) << endl;
    cout << "c3 small: " << c3.total_items(Stress_ball_sizes::small) << endl;
    cout << "c3 medium: " << c3.total_items(Stress_ball_sizes::medium) << endl;
    cout << "c3 large: " << c3.total_items(Stress_ball_sizes::large) << endl;
    cout << "c3 total: " << c3.total_items() << endl << endl;

    cout << "-----=======+++++++++=======-----" << endl << endl;



    // (e) Swap two collections in (b). Print its elements to check if they correctly swapped.
    swap(c1, c2);

    cout << "Outputting swapped c1..." << endl;

    c1.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;

    cout << "Outputting swapped c2..." << endl;

    c2.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;


    // (f) Sort the first collection in (b). Print its elements to check if it is correctly sorted.
    
    sort_by_size(c3, Sort_choice::selection_sort);

    cout << "Outputting selection sorted c3..." << endl;

    c3.print_items();

    cout << "-----=======+++++++++=======-----" << endl << endl;

    // (g) You can do other tests not mentioned above in order to be sure that all you implemented functions are
    // correct.

    cout << "Removing small and 2 random stress balls from c3..." << endl;

    Stress_ball sb1(Stress_ball_colors::red, Stress_ball_sizes::small);
    Stress_ball sb2(Stress_ball_colors::blue, Stress_ball_sizes::small);
    Stress_ball sb3(Stress_ball_colors::green, Stress_ball_sizes::small);
    Stress_ball sb4(Stress_ball_colors::yellow, Stress_ball_sizes::small);

    c3.remove_this_item(sb1);
    c3.remove_this_item(sb2);
    c3.remove_this_item(sb3);
    c3.remove_this_item(sb4);
    c3.remove_any_item();
    c3.remove_any_item();


    c3.print_items();

    cout << "c3 red: " << c3.total_items(Stress_ball_colors::red) << endl;
    cout << "c3 blue: " << c3.total_items(Stress_ball_colors::blue) << endl;
    cout << "c3 yellow: " << c3.total_items(Stress_ball_colors::yellow) << endl;
    cout << "c3 green: " << c3.total_items(Stress_ball_colors::green) << endl;
    cout << "c3 small: " << c3.total_items(Stress_ball_sizes::small) << endl;
    cout << "c3 medium: " << c3.total_items(Stress_ball_sizes::medium) << endl;
    cout << "c3 large: " << c3.total_items(Stress_ball_sizes::large) << endl;
    cout << "c3 total: " << c3.total_items() << endl << endl;

    cout << "-----=======+++++++++=======-----" << endl << endl;


    return 0;
}