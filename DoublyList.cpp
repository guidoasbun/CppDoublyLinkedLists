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
                if (current->getData() == valueToDelete)
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

void DoublyList::printCount() const
{
    cout << count;
}

void DoublyList::printPrev() const
{
    cout << first->getPrev();
}

void DoublyList::printNext() const
{
    cout << last->getNext();
}

void DoublyList::createAList()
{
    /*
    NOTE:

        * RESTRICTION: You can declare ONLY ONE pointer
          and reuse it throughout the function.

        * Pay CLOSE attention to instructions.
*/

    /*----------------------------------------------------------------
    SECTION 1
    ------------------------------------------------------------------*/

    // Create a dynamic node that stores the value 2 and make
    // this node to be the first node of the calling object.
    // List becomes: 2
    // RESTRICTIONS:
    //		Use the overloaded constructor.
    //		Do NOT create a pointer.
    //		Max: 3 statements

    first = new Node(2, nullptr, nullptr);
    last = first;
    ++count;

    /*----------------------------------------------------------------
	SECTION 2
	------------------------------------------------------------------*/

    // Create another node that stores the value 3 and
    // insert this node to the left of the node that is
    // storing value 2.
    // List becomes: 3 2
    // RESTRICTIONS:
    //		NO loops.
    //		Do NOT create a pointer.
    //		Max: 3 statements

    first = new Node(3, nullptr, first);
    first->getNext()->setPrev(first);
    ++count;

    /*----------------------------------------------------------------
	SECTION 3
	------------------------------------------------------------------*/

    // Create another node that stores the value 4 and
    // insert this node to the right of the node that is
    // storing value 3.
    // List becomes: 3 4 2
    // RESTRICTIONS:
    //		NO loops.
    //		Create a new pointer for this step.
    //		Pointer identifier: pNode
    //		Max: 4 statements

    Node* pNode = new Node(4, first, last);
    first->setNext(pNode);
    last->setPrev(pNode);
    ++count;

    /*----------------------------------------------------------------
	SECTION 4
	------------------------------------------------------------------*/

    // Delete the first node.
    // List becomes: 4 2
    // RESTRICTIONS:
    //		NO loops.
    //		Do NOT use pNode.
    //		Do NOT create a pointer.
    //		Do NOT create a new node.
    //		Max: 4 statements


}

DoublyList::~DoublyList()
{
    clearList();
}

