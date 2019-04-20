//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Node
{
public:

    Node(int data)
    {
        m_data = data;
    };

    Node(Node *object)
    {
        m_data = object->GetData();
        m_next = object->GetNext();
    };

    void SetNext(Node *nextNode)
    {
        m_next = nextNode;
    };

    void SetData(int data) { m_data = data; };

    Node* GetNext() { return m_next; };
    int GetData() { return m_data; };


private:
    int m_data;
    Node *m_next;
};

class LinkedList
{
public:
    LinkedList()
    {
        m_head = nullptr;
        m_tail = nullptr;
    };

    void SetHead(Node *node)
    {
        m_head = node;
        m_head->SetNext(node->GetNext());
        m_head->SetData(node->GetData());
    };

    void SetTail(Node *node)
    {
        m_tail = node;
        m_tail->SetNext(node->GetNext());
        m_tail->SetData(node->GetData());
    };

    Node* GetHead() { return m_head; };
    Node* GetTail() { return m_head; };

private:
    Node * m_head, *m_tail;
};


int main()
{
    cout << "Hello Linked list program\n";

    cout << "Let's make a linked list of 5 nodes\n";
    LinkedList *linkedList1 = new LinkedList();

    int ii = 0;
    Node *node1 = new Node(ii);
    ii++;
    Node *node2 = new Node(ii);
    ii++;
    Node *node3 = new Node(ii);
    ii++;
    Node *node4 = new Node(ii);
    ii++;
    Node *node5 = new Node(ii);
    ii++;

    linkedList1->SetHead(node1);
    linkedList1->SetTail(node5);

    cout << "Head node data = " << linkedList1->GetHead()->GetData() << endl;
    cout << "Tail node data = " << linkedList1->GetTail()->GetData() << endl;
    cout << "Node 1 data = " << node1->GetData() << endl;
    cout << "Node 5 data = " << node5->GetData() << endl;
    delete linkedList1;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}
