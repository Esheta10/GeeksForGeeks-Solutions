// User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/
Node *deleteHead(Node *head) {
    // Your code here
    if(head==NULL)
        return NULL;
        
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    
    Node* newHead = head->next;
    newHead->prev = NULL;
    delete head;
    
    return newHead;
}
