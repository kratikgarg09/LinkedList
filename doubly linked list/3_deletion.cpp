// Inclueding Header files

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// making node for DLL
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

// function for printing the DLL
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

// Function for getting length of DLL
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

// function for inserting the value in DLL
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

// function for deleting the value in DLL by given position
void deleteByPosition(Node *&head, int position)
{
    if (position == 1)
    {
        Node *forward = head->next;
        forward->prev = NULL;
        head = forward;
        forward = NULL;
        delete forward;
    }
    else
    {
        int cnt = 1;
        Node *currNode = head;
        Node *prevNode = NULL;

        while (cnt < position)
        {
            prevNode = currNode;
            currNode = currNode->next;
            cnt++;
        }
        currNode->prev = NULL;
        prevNode->next = currNode->next;
        currNode->next = NULL;
        delete currNode;
    }
}

// function for deleting the value in DLL by given value
void deleteByValue(Node *&head, int val)
{
    Node *currNode = head;
    Node *prevNode = NULL;
    if (currNode->next != NULL && currNode->data == val)
    {
        head = currNode->next;
        currNode->next = NULL;
        head->prev = NULL;
        delete currNode;
    }
    else
    {
        while (currNode != NULL && currNode->data != val)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        if(currNode == NULL){
            cout << "value not found" << endl;
        }
        currNode->prev = NULL;
        prevNode->next = currNode->next;
        currNode->next = NULL;
        delete currNode;
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

    deleteByPosition(head, 2);
    print(head);

// deleting value from DLL
    int val;
    cout << "Enter the value which you want to delete : ";
    cin >> val;
    deleteByValue(head, val);
    print(head);

    return 0;
}