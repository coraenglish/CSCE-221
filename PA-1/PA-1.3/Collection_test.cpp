#include <iostream>
using namespace std;

void test_stress_balls();
void test_jeans();

int main() {
    int answer;
    cout << "What version to test: stress_ball (=0) or jeans (=1): ";
    cin >> answer;

    if (answer == 0)
        test_stress_balls();
    else if (answer == 1)
        test_jeans();
    else
        cout << "Wrong value: " << answer << endl;
        
    return 0;
}