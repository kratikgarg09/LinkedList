#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node()
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

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a new node for data d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
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

// ***** Function to delete any node or value at any position

void deleteNode(Node *&head, int position)
{
    // code for deleting value present at start
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free
        temp->next = NULL;
        delete temp;
    }

    // Code for deleting value present at any node
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        int cnt = 1;

        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        // memory free
        curr->next = NULL;
        delete curr;
    }
}

void deleteValue(Node* &head, int value)
{

	// Store head node
	Node* curr = head;
	Node* prev = NULL;

	// If head node itself holds
	// the value to be deleted
	if (curr->next != NULL && curr->data == value) {
	
	// Changed head
		head = curr->next;
	
	// free old head
        curr->next = NULL;
		delete curr;
		return;
	}

	// Else Search for the value to be
	// deleted, keep track of the
	// previous node as we need to
	// change 'prev->next'
	else {
		while (curr != NULL && curr->data != value) {
			prev = curr;
			curr = curr->next;
		}

		// If value was not present in linked list

		if (curr == NULL){
            cout << "We didn't find the value which you entered" << endl; 
            return;
        }

		// Unlink the node from linked list
		prev->next = curr->next;
        curr->next = NULL;
        cout << "deletion is done";
                
		// Free memory
		delete curr;
	}
}

int main()
{
    // Creating a new node
    Node *node1 = new Node(10);

    // Head pointed to node1
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 12);
    printLinkedList(head);

    insertAtTail(tail, 15);
    printLinkedList(head);

    insertAtTail(tail, 15);
    printLinkedList(head);

    insertAtPosition(tail, head, 5, 77);
    printLinkedList(head);

    cout << "Head = " << head->data << endl;
    cout << "Tail = " << tail->data << endl;

    deleteNode(head, 5);
    printLinkedList(head);

    int value;
    cout << "please enter the value to delete" << endl;
    cin >> value;

    deleteValue(head, value);
    printLinkedList(head);
 
    return 0;
}