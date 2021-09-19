//
// Created by Rodrigo Asbun on 9/18/21.
//

#include "DoublyList.h"

using namespace std;

void DoublyList::insertFront(int newData)
{
    if (first == nullptr)
    {
        first = new Node(newData, nullptr, nullptr);
        last = first;
        // Common error: Forgetting to reset pointer last.
    }
    else
    {
        first = new Node(newData, nullptr, first);
        first->getNext()->setPrev(first);
        // Common error: Forgetting to connect pointer
        // prev of what is now the second node to the
        // new first node.
    }

    ++count;
}

void DoublyList::printForward() const
{
    Node* current = first;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getNext();
    }
}

void DoublyList::printReverse() const
{
    Node* current = last;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getPrev();
    }
}

void DoublyList::clearList()
{
    Node* temp = first;

    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }

    last = nullptr;
    // Don't forget to reset the last pointer to nullptr.
    count = 0;
}

int DoublyList::front() const
{
    return first->getData();
}

int DoublyList::back() const
{
    return last->getData();
}

void DoublyList::insertBack(int newData)
{
    if (first == nullptr)
    {
        first = new Node(newData, nullptr, nullptr);
        last = first;
    }
    else
    {
        last->setNext(new Node(newData, last, nullptr));
        last = last->getNext();
    }
    ++count;
}

void DoublyList::moveToList(DoublyList &toList)
{
    // Assume parameter object is empty.
    // Do NOT assume calling object is empty.
    // Do nothing if calling object is empty.
    if (count != 0)
    {
        toList.first = first;
        toList.last = last;
        toList.count = count;

    // Detach the calling object from the nodes that
    // now belong to the parameter object.
        first = nullptr;
        last = nullptr;
        count = 0;
    // The calling object still exists, but it is empty
    // as it was when it was created before inserting
    // any elements.
    }
}

DoublyList::~DoublyList()
{
    clearList();
}

