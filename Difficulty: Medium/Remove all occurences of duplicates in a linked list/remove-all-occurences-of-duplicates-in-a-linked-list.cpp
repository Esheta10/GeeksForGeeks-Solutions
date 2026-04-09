// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        
        Node* dummy = new Node(-1);
        dummy->next = head;
        
        Node* curr = head;
        Node* prev = dummy;
        
        while(curr != NULL && curr->next != NULL){
            
            if(curr->data == curr->next->data){
                
                while(curr->next != NULL && curr->data == curr->next->data){
                    curr = curr->next;
                }
                prev->next = curr->next; // skip all duplicates
            } else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};