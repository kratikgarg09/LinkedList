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
};

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

int main()
{

    return 0;
}