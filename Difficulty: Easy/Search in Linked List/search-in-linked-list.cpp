/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        
        Node *current = head;
        
        while(current != NULL){
            
            if(current->data == key)
                return true;  // return current;
                
            current = current->next;
        }
        return false;
    }
};
