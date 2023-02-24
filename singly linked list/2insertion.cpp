#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    Node()
    {
        int value = this->data;

        // memmory freeing
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memmory is now free for node with data : " << value << endl;
    }
};

// function to inserting any value at starting point

void insertAtHead(Node *&head, int d)
{
    // creating new node

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// function to inserting any value at ending point

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// **** Now We inserting any value or data at a given node or position****

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // creating a new node for data d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
}

void printLinkedList(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    Node *curr = head->next;
    while (curr != NULL && curr != head)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return false;
    }
    if (curr == head)
    {
        return true;
    }
    return false;
}

int main()
{
    // Creating a new node
    Node *node1 = new Node(10);

    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // Head pointed to node1
    Node *head = node1;

    // printLinkedList(head);
    // insertAtHead(head, 12);

    Node *tail = node1;

    insertAtTail(tail, 12);
    printLinkedList(head);

    insertAtTail(tail, 15);
    printLinkedList(head);
/*
    insertAtTail(tail, 18);
    printLinkedList(head);

    insertAtPosition(tail, head, 5, 77);
    printLinkedList(head);

    cout << "Head = " << head->data << endl;
    cout << "Tail = " << tail->data << endl;

    cout << "Address of Head = " << head->next << endl;
    cout << "Address of Tail = " << tail->next << endl; */
    
    if (isCircular(head))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false";
    }
    return 0;
}