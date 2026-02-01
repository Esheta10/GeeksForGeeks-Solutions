/*
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertPos(Node *head, int pos, int val) {
        // code here
        Node* newNode = new Node(val);
        
        Node* current = head;
        
        if(pos == 1){
            newNode->next = head;
            return newNode;
        }
        if(current == NULL){
            delete newNode;
            return head;
        }
        for(int i=1; i<pos-1 && current != NULL; i++){
            current = current->next;
        }
        Node* temp = current->next;
        current->next = newNode;
        newNode->next = temp;
        
        return head;
    }
};