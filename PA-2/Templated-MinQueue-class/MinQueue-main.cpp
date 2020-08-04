#include "MinQueue.h"

#include <iostream>

using namespace std;

int main() {

    MinQueue<int> mq;

    cout << "Testing error handling for min on empty queue... " << endl;

    try {
        cout << mq.min() << endl;
    } catch (runtime_error & e) {
        cout << "ERROR... " << e.what() << endl << endl;
    }

    cout << "Enqueue elements 1-10 into mq" << endl;
    for (int i = 1; i <= 10; i++) 
    {
        mq.enqueue(i);
    }
    cout << mq << endl;

    cout << "Original min: " << mq.min() << endl << endl;

    cout << "Dequeue elements 1-5 from mq" << endl;
    for (int i = 1; i <= 5; i++) 
    {
        mq.dequeue();
    }
    cout << mq << endl << endl;

    cout << "Enqueue some more elements: " << endl;
    mq.enqueue(2);
    mq.enqueue(4);
    mq.enqueue(3);
    cout << mq << endl;


    cout << "New min: " << mq.min() << endl << endl;




    return 0;
}