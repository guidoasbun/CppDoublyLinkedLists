#include "DoublyList.h"

#include <iostream>
using namespace std;

int main()
{
    DoublyList myList;

    myList.insertFront(5);
    myList.insertFront(9);
    myList.insertFront(3);
    myList.insertFront(5);
    myList.insertFront(8);


    cout << "front: " << myList.front() << endl;
    cout << "back: " << myList.back() << endl;


    cout << "List print forward: ";
    myList.printForward();
    cout << endl;
    cout << "List print reverse: ";
    myList.printReverse();
    cout << endl;

    myList.clearList();

    return 0;
}









/*
 *     cout << "Inserted: 1 2 3 4\n";
    cout << "List print forward: ";
    myList.printForward();
    cout << endl;
    cout << "List print reverse: ";
    myList.printReverse();

    myList.clearList();

    cout << "\nPrint the list after emptying it...\n";

    cout << "List print forward: ";
    myList.printForward();
    cout << endl;
    cout << "List print reverse: ";
    myList.printReverse();
    cout << endl;
 */
