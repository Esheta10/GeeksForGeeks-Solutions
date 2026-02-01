/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // Empty list
        if(head == NULL){
            return NULL;
        }
        
        // Delete head (position 1)
        if(x == 1){
            Node* temp = head;
            head = head->next;
            if(head != NULL){
                head->prev = NULL;
            }
            delete temp;
            return head;
        }
        
        // Traverse to the x-th node (the node to delete)
        Node* current = head;
        for(int i = 1; i < x && current != NULL; i++){
            current = current->next;
        }
        
        // Check if position exists
        if(current == NULL){
            return head;  // Position out of bounds
        }
        
        // Update the previous node's next pointer
        if(current->prev != NULL){
            current->prev->next = current->next;
        }
        
        // Update the next node's prev pointer
        if(current->next != NULL){
            current->next->prev = current->prev;
        }
        
        // Delete the node
        delete current;  // ✅ Actually free the memory!
        
        return head;
    }
};