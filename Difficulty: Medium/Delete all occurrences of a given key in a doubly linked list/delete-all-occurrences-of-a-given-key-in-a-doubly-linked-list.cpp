/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // code here
        struct Node* curr = *head_ref;
        
        while(curr != NULL){
            
            struct Node* next = curr->next;
            if(curr->data == x){
                
                if(curr->prev != NULL){
                    
                    curr->prev->next = curr->next;
                } else {
                    *head_ref = curr->next;
                }
                
                if(curr->next != NULL){
                    curr->next->prev = curr->prev;
                }
                
                delete curr;
            }
            curr = next;
        }
    }
};