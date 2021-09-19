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

void DoublyList::deleteElement(int valueToDelete)
{
    // Case 1: List is empty
    if (first == nullptr) // OR: if (count == 0)
    {
    // Use cerr, rather than cout (why?)
        cerr << "Cannot delete from an empty list.\n";
    }
    else
    {
        // Set a Boolean value to keep track of
        // whether the item is found or not.
        bool found = false;
        // Case 2: Node to be delete is the first node.
        if (first->getData() == valueToDelete)
        {
            // If there is only one node...
            if (first == last)
            // OR: if (count == 1)
            {
                delete first;
                first = last = nullptr;
            }
            else
            // If there is more than one node...
            {
                first = first->getNext();
                delete first->getPrev();
                first->setPrev(nullptr);
            }
            found = true;
            --count;
        }
        // Case 3: Node to delete is the last node.
        else if (last->getData() == valueToDelete)
        {
            last = last->getPrev();
            delete last->getNext();
            last->setNext(nullptr);
            found = true;
            --count;
        }
        // Case 4: Node to delete is somewhere in the list.
        else
        {
            // Create a pointer to traverse the list.
            // Start pointing at the second node, because
            // you already know that it is not the first node.
            Node* current = first->getNext();
            while (!found && current != nullptr)
            // Don't let the WHILE loop continue if
            // the element is found!
            {
                if (current->getData() == elemToDelete)
                {
                    // connect previous and next node
                    current->getPrev()->setNext(current->getNext());
                    current->getNext()->setPrev(current->getPrev());
                // NOTE: It would be more efficient to create
                // a pointer pointing to the previous node and
                // another pointer pointing to the next node,
                // because we would not have to call too many
                // functions, but this is good practice for the exam.
                    delete current;
                    current = nullptr;
                // Don't leave a dangling pointer!
                    found = true;
                    --count;
                }
                else
                    current = current->getNext();
            }
        }
        if (!found)
            cout << "Element to be deleted is not in the list." << endl;
    }
}

DoublyList::~DoublyList()
{
    clearList();
}

