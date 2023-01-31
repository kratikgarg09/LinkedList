#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    // creating new node

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// function to inserting any value at ending point

void insertAtTail(Node *&head, int d)
{
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->next == NULL)
        {
            Node *temp = new Node(d);
            curr->next = temp;
            temp = curr;
            curr = curr->next;
        }
        curr = curr->next;
    }
}

// **** Now We inserting any value or data at a given node or position****

void insertAtPosition(Node *&head, int d, int position)
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
        insertAtTail(head, d);
        return;
    }
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseLL(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

void reverseLL_recursively(Node *&head, Node *curr, Node *prev = NULL)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    Node *temp = curr->next;
    reverseLL_recursively(head, temp, curr);
    curr->next = prev;
}

Node *reverseLL_recursive2(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *chotahead = reverseLL_recursive2(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotahead;
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
    reverseLL(head);
    print(head);

    reverseLL_recursively(head, head, NULL);
    print(head);
    
    head = reverseLL_recursive2(head);
    print(head);
    return 0;
}