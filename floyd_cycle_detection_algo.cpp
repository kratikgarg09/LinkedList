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
    if(head == NULL || pointOfIntersection == NULL){
        return NULL;
    }
    Node* slow = head;
    while(slow!= pointOfIntersection){
        slow = slow->next;
        pointOfIntersection = pointOfIntersection->next;
    }
    return slow;
}

void removeLoop(Node* head){
    Node* startingNode = getStarting(head);
    
    if(head == NULL || startingNode == NULL){
        return;
    }

    Node* curr = head;
    while (curr->next != startingNode)
    {
        curr = curr->next;
    }
    curr->next = NULL;
    
}
int main()
{

    return 0;
}