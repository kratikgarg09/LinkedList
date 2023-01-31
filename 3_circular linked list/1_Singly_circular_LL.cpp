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
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << val << endl;
    }
};

void insertNode(Node *&head, int element, int data)
{
    // assuming that the list is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        newNode->next = newNode;
    }

    else
    {
        Node *curr = head;
        while (curr->data != element)
        {
            curr = curr->next;
            if(curr == head && curr->data != element){
                cout << "element Not found" << endl;
                return;
            }
            
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
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

void deleteNode(Node *&head, int value)
{

    if (head == NULL)
    {
        cout << "your list is empty" << endl;
        return;
    }
    else
    {
        Node *prev = head;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // for single node CLL
        if (curr == prev)
        {
            head = NULL;
        }
        // for >= 2 nodes
        else if (head == curr)
        {
            head = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

bool isCircular(Node *head)
{
    if(head == NULL){return true;}
    Node* curr = head;
    while (curr!= NULL && curr != head)
    {
        curr = curr->next;
    }
    if(curr == NULL){
        return false;
    }
    if(curr == head){
        return true;
    }
    return false;  
}

Node* floydsCycleDetect(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL){fast = fast->next;}
        slow = slow->next;
        if(fast == slow){
            return slow;
        }
    }
    return NULL;
}

Node* getStarting(Node* head){
    Node* pointOfIntersection = floydsCycleDetect(head);
    Node* slow = head;
    while(slow!= pointOfIntersection){
        slow = slow->next;
        pointOfIntersection = pointOfIntersection->next;
    }
    return slow;
}

int main()
{
    Node *head = NULL;

    insertNode(head, 3, 2);
    print(head);

    insertNode(head, 2,3 );
    print(head);

    insertNode(head, 3, 56);
    print(head);

    insertNode(head, 5,9);
    print(head);

    // deleteNode(head, 3);
    // print(head);

    if(isCircular(head)){
        cout << "true"  << endl;
    }
    else{
        cout << "false";
    }
    cout << getStarting(head)->data << endl;
    return 0;
}