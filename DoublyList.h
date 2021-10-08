//
// Created by Rodrigo Asbun on 9/18/21.
//

#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#include <iostream>

class Node
{
public:
    // Default constructor
    Node() : data(0), prev(nullptr), next(nullptr) {}
    // Constructor
    Node(int theData, Node* prevLink, Node* nextLink)
            : data(theData), prev(prevLink), next(nextLink) {}
    // Gets
    int getData() const { return data; }
    Node* getPrev() const { return prev; }
    Node* getNext() const { return next; }
    // Sets
    void setData(int theData) { data = theData; }
    void setPrev(Node* prevLink) { prev = prevLink; }
    void setNext(Node* nextLink) { next = nextLink; }
    ~Node(){}
private:
    // To simplify, we are using only one piece of data.
    int data;
    Node* prev;
    Node* next;
};

class DoublyList
{
public:
    // Default constructor
    DoublyList() : first(nullptr), last(nullptr), count(0) {}



    void printForward() const;
    void printReverse() const;
    int front() const;
    int back() const;

    void insertFront(int newData);
    void insertBack(int newData);
    void moveToList(DoublyList& toList);
    void deleteElement(int valueToDelete);

    // Lab2
    void printCount() const;
    void printPrev() const;
    void printNext() const;
    void createAList();

    void clearList();
    // Destructor

    void swapFirstLast();

    ~DoublyList();

private:
    // Pointer to the first node on the list.
    Node *first;
    // Pointer to the last node on the list.
    Node *last;
    // Number of nodes in the list.
    int count;
};

#endif //DOUBLYLINKEDLISTS_DOUBLYLIST_H
