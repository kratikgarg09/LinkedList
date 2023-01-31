#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int getLength(Node *&head)
{
    Node *curr = head;
    int cnt = 0;
    while (curr != NULL)
    {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, int d)
{
    Node *curr = head;
    while (curr->next != NULL)
    {
        // if (curr->next == NULL)
        // {
        //     Node *temp = new Node(d);
        //     curr->next = temp;
        //     temp = curr;
        //     curr = curr->next;
        // }
        curr = curr->next;
    }
    Node *temp = new Node(d);
    curr->next = temp;
    temp->prev = curr;
}

void insertAtPosition(Node *&head, int data, int position)
{

    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    int cnt = 1;
    Node *curr = head;
    while (cnt < position - 1)
    {
        curr = curr->next;
        cnt++;
    }
    Node *nodeToInsert = new Node(data);
    Node *forward = curr->next;
    curr->next = nodeToInsert;
    nodeToInsert->next = forward;
    nodeToInsert->prev = curr;

    if (curr->next == NULL)
    {
        insertAtTail(head, data);
        return;
    }
}

int main()
{
    // Node *node1 = new Node(11);
    Node *head = NULL;
    // print(node1);

    insertAtHead(head, 12);
    // print(head);

    insertAtHead(head, 13);
    // print(head);

    insertAtHead(head, 14);
    // print(head);

    insertAtHead(head, 15);
    // print(head);

    insertAtTail(head, 16);
    print(head);

    insertAtPosition(head, 100, 6);
    print(head);

    return 0;
}