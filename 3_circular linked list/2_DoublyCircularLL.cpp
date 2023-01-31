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

void insertNode(Node *&head, int element, int value)
{
    if (head == NULL)
    {
        Node *newNode = new Node(value);
        head = newNode;
        newNode->prev = newNode->next;
        newNode->next = newNode->prev;
    }
    else
    {
        Node *curr = head;
        while (curr->data != element)
        {
            curr = curr->next;
            if(curr == head && curr->data != element)
            {
                cout << "element Not found" << endl;
                return;
            }
        }
        Node *nodeToInsert = new Node(value);
        Node *forward = curr->next;
        curr->next = nodeToInsert;
        nodeToInsert->next = forward;
        nodeToInsert->prev = curr;
    }
}

void print(Node *&head)
{
    Node *curr = head;
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    do
    {
        cout << head->data << " ";
        head = head->next;
    } while (head != curr);

    cout << endl;
}

int main()
{
    Node *head = NULL;
    insertNode(head,3,5);
    print(head);
    insertNode(head,5,3);
    print(head);
    insertNode(head,3,5);
    print(head);
    insertNode(head,3,5);
    print(head);
    insertNode(head,3,5);
    print(head);
    insertNode(head,3,5);
    print(head);
    return 0;
}