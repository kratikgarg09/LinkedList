#include<iostream>
#include<bits/stdc++.h> 

using namespace std; 

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* curr = head;
    while (curr!=NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;        
}

int getLength(Node* &head){
    Node*curr = head;
    int cnt = 0;
    while (curr!=NULL)
    {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

int main() 
{ 
    Node* node1 = new Node(11);
    Node* head = node1;
    print(node1);
    cout << getLength(head) << endl;

    return 0;
}