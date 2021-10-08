#include "DoublyList.h"

#include <iostream>
using namespace std;

int main()
{
    DoublyList myList;
    DoublyList myList2;

    myList.createAList();

    myList2.insertFront(4);
    myList2.insertFront(3);
    myList2.insertFront(2);
    myList2.insertFront(1);

    cout << "myList: " << endl;
    myList.printForward();
    cout << endl;

    cout << "myList2: " << endl;
    myList2.printForward();
    cout << endl;

    myList.swapLast(myList2);

    cout << "myList: " << endl;
    myList.printForward();
    cout << endl;

    cout << "myList2: " << endl;
    myList2.printForward();
    cout << endl;


//    cout << "Reverse Print: ";
//    myList.printReverse();
//    cout << endl;
//
//    cout << "Count: ";
//    myList.printCount();
//    cout << endl;
//
//    cout << "First Element: " << myList.front() << endl;
//    cout << "Last Element: " << myList.back() << endl;
//
//    cout << "Pointer prev of the first node: ";
//    myList.printPrev();
//    cout << endl;
//
//    cout << "Pointer next of the last node: ";
//    myList.printNext();
//    cout << endl;

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
