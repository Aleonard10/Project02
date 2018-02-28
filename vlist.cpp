#include <iostream>
#include "vlist.h"
#include "video.h"

using namespace std;

// on some machines member variables are not automatically initialized to 0
vlist::vlist()
{
    m_head = NULL;
}

// delete all Nodes in the list
// since they are dynamically allocated using new, they won't go away
// automatically when the list is deleted
// Rule of thumb: destructor deletes all memory created by member functions
vlist::~vlist()
{
    // cout << "List::~List() was called" << endl;

    Node *ptr = m_head;
    while (ptr != NULL)
    {
        Node *temp;

        temp = ptr;
        ptr = ptr->m_next;
        delete temp;
    }
}

// always insert at the front of the list
// Note: this works even in the SPECIAL CASE that the list is empty
void vlist::insert(video* value)
{
    m_head = new Node(value, m_head);
}

// iterate through all the Nodes in the list and print each Node
void vlist::print()
{
    Node *ptr = m_head;
    while (ptr != NULL)
    {
        ptr->m_value->print();
        ptr = ptr->m_next;
    }

    /* The following is the same as the above loop
    for (Node *ptr = m_head; ptr; ptr = ptr->m_next)
    {
        cout << ptr->m_value << endl;
    }
    */
}

void vlist::insert_at_end(video* value)
{
    Node *ptr = m_head;
    if (ptr == NULL)
    {
        m_head = new Node(value, m_head);
    }
    else
    {
        while (ptr->m_next != NULL)
        {
            ptr = ptr->m_next;
        }

        ptr->m_next = new Node(value, NULL);
    }



}
