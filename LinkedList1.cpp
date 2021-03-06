// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

static int max_size = 1000;

class SinglyListNode
{
public:
    int val = 0;
    SinglyListNode *next;
    SinglyListNode() : val(0) {};
    SinglyListNode(int x) : val(x), next(nullptr) {};
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : m_nodes(max_size)
    {
        m_head = &m_nodes[0];
        m_tail = &m_nodes[max_size - 1];
    };

    MyLinkedList(SinglyListNode &head)
    {
        m_nodes.reserve(max_size);
        m_nodes[0] = head;
        m_head = &m_nodes[0];
        m_tail = &m_nodes[max_size-1];
    };

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= (max_size))
        {
            return -1;
        }

        return m_nodes[index].val;
    };

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        SinglyListNode *curr = new SinglyListNode(val);
        m_nodes.resize(m_nodes.size() + 1);
        curr->next = m_head;
        m_head = curr;
        m_nodes.insert(m_nodes.begin(), *curr);
    };

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        SinglyListNode *curr = new SinglyListNode(val);
        m_nodes.resize(m_nodes.size() + 1);
        curr->next = nullptr;
        if (m_tail != nullptr)
        {
            m_tail->next = curr;
            m_tail = curr;
        }
        m_nodes.push_back(*curr);
    };

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
        
    };

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {

    };

private:
    std::vector<SinglyListNode> m_nodes;
    SinglyListNode *m_head = nullptr;
    SinglyListNode *m_tail = nullptr;
};



/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList obj = new MyLinkedList();
* int param_1 = obj.get(index);
* obj.addAtHead(val);
* obj.addAtTail(val);
* obj.addAtIndex(index,val);
* obj.deleteAtIndex(index);
*/
