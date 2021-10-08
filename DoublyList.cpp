//
// Created by Rodrigo Asbun on 9/18/21.
//

#include "DoublyList.h"

using namespace std;

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

    first = first->getNext();
    delete first->getPrev();
    first->setPrev(nullptr);
    --count;

    /*----------------------------------------------------------------
	SECTION 5
	------------------------------------------------------------------*/

    // Insert three nodes at the end of the list storing
    // 5 6 7 in this order.
    // List becomes: 4 2 5 6 7
    // RESTRICTIONS:
    //		NO loops.
    //		Do NOT use pNode.
    //		Do NOT create a pointer.
    //		Max: 7 statements

    last->setNext(new Node(5, last, nullptr));
    last = last->getNext();

    last->setNext(new Node(6, last, nullptr));
    last = last->getNext();

    last->setNext(new Node(7, last, nullptr));
    last = last->getNext();

    count += 3;

    /*----------------------------------------------------------------
	SECTION 6
	------------------------------------------------------------------*/

    // Move last node to second position.
    // Note that you are NOT replacing values, you are
    // NOT creating new nodes, and you are NOT moving nodes,
    // but only rearranging pointers to change the sequence
    // of the list.
    // Here, the steps are very important. Carefully think
    // how you can rearrange the order of nodes around without
    // losing any nodes and keeping all pointers pointing to the
    // correct nodes.
    // RESTRICTIONS:
    //		NO loops.
    //		Do NOT use pNode.
    //		Do NOT create a pointer.
    //		Do NOT create a new node.
    //		Max: 6 statements
    // List becomes: 4 7 2 5 6

    last->setNext(first->getNext());
    first->getNext()->setPrev(last);
    first->setNext(last);
    last = last->getPrev();
    last->setNext(nullptr);
    first->getNext()->setPrev(first);

    /*----------------------------------------------------------------
	SECTION 7
	------------------------------------------------------------------*/

    // Move the first node in between the node before last and
    // last node (the second node will become the first node
    // in the list, and the first node will become the before-last
    // node in the list).
    //	RESTRICTIONS:
    //		NO loops.
    //		Do NOT use pNode.
    //		Do NOT create a pointer.
    //		Do NOT create a new node.
    //		Max: 6 statements
    // List becomes: 7 2 5 4 6

    first->setPrev(last->getPrev());
    last->getPrev()->setNext(first);
    last->setPrev(first);
    first = first->getNext();
    first->setPrev(nullptr);
    last->getPrev()->setNext(last);

    /*----------------------------------------------------------------
	SECTION 8
	------------------------------------------------------------------*/

    // WITHOUT moving any nodes, swap around the values to
    // create an ordered list.
    // Note that there is no need to move the value 5.
    // You may declare an int, BUT do NOT use any literals.
    // List becomes: 2 4 5 6 7
    //	RESTRICTIONS:
    //		Create a variable of type int to swap.
    //		NO loops.
    //		Do NOT use pNode.
    //		Do NOT create a pointer.
    //		Do NOT create a new node.
    //		Max: 5 statements

    first->setData(2);
    first->getNext()->setData(4);
    last->setData(7);
    last->getPrev()->setData(6);

    /*----------------------------------------------------------------
	SECTION 9
	------------------------------------------------------------------*/

    // Add two nodes storing 1 and 3 to complete the ordered list.
    // List becomes: 1 2 3 4 5 6 7
    //	RESTRICTIONS:
    //		NO loops.
    //		Do NOT create a pointer.
    //		Max: 6 statements

    first->getNext()->setPrev(new Node(3, first, first->getNext()));
    first->setPrev(new Node(1, nullptr, first));
    first->setNext(first->getNext()->getPrev());
    first = first->getPrev();
    count += 2;

    /*----------------------------------------------------------------
	SECTION 10
	------------------------------------------------------------------*/
}

void DoublyList::swapLast(DoublyList &otherList)
{
    last->getPrev()->setNext(otherList.last);
    otherList.last->getPrev()->setNext(last);
    last = otherList.last;
    otherList.last = last->getPrev()->getNext();
    last->setPrev(otherList.last->getPrev());
    otherList.last->setPrev(last->getPrev());
}

DoublyList::~DoublyList()
{
    clearList();
}

