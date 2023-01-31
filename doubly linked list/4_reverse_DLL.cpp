#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtPosition(Node *&head, int data, int position)
{
    if (position == 1)
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
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->next == NULL)
            {
                Node *temp = new Node(data);
                curr->next = temp;
                temp = curr;
                curr = curr->next;
            }
            curr = curr->next;
        }
        return;
    }
}

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

void reverseDLL(Node *&head)
{
    Node *temp = NULL;
    Node *currNode = head;

    while (currNode != NULL)
    {
        temp = currNode->prev;
        currNode->prev = currNode->next;
        currNode->next = temp;
        currNode = currNode->prev;
    }
    if (temp != NULL)
    {
        head = temp->prev;
    }
}

int main()
{
    Node *head = NULL;
    int n;
    cout << "Enter the size of linked list" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        insertAtPosition(head, data, i + 1);
    }
    print(head);
    reverseDLL(head);
    print(head);
    return 0;
}