#include <bits/stdc++.h> 
/**********************************************************************

    Following is the class structure of the Node class for reference:

    class Node{
    public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };

********************************************************************/
Node* findMid(Node* head){
    if(head == NULL){return NULL;}
    Node* fast = head->next;
    Node* slow = head;
    while(fast!=NULL && fast->next!= NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* mergeTwoSortedLists(Node* l1, Node*l2){
    if(l1 == NULL)return l2;
    if(l2 == NULL)return l1;
    
    if(l1->data < l2->data ){
        l1->next = mergeTwoSortedLists(l1->next,l2);
        return l1;
    }
    else{
        l2->next = mergeTwoSortedLists(l1,l2->next);
        return l2;
    }
}
Node *sortLL(Node *head){
    // Base case
    if(head == NULL || head->next == NULL){
        return head;
    }
    //finding mid
    Node* mid = findMid(head);
    
    //break the list in two halves;
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;
    
    // recursive call 
    left = sortLL(left);
    right = sortLL(right);
    
    // merge both the lists
    Node* result = mergeTwoSortedLists(left,right);
    return result;
}