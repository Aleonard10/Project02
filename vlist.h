// demonstrate a simple linked-list of integers
#ifndef VLIST_H
#define VLIST_H
#include "video.h"
class vlist
{
    public:
        vlist();
        ~vlist();
        void insert(video* value); // insert at beginning of list
        void print();
        int sum();
        void insert_at_end(video* value);
    private:
        class Node
        {
            public:
                // small functions can be inserted into the class definition
                // don't put large functions in the class definition
                Node(video* value, Node *next)
                {m_value = value; m_next = next;}
                video* m_value;
                Node *m_next;
        };
        Node *m_head;
};

#endif
