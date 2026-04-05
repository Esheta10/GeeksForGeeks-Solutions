/*
class Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // code here
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        
        // Find the length of linked list
        Node* curr = head;
        int len = 1;
        while(curr->next != NULL){
            curr = curr->next;
            len++;
        }
        
        // Reorder / Resize k
        k = k % len;
        
        if(k == 0)
            return head;
        
        // Traverse upto 1 node before k and set it to Null by traversing till len - k -1
        Node* newTail = head;
        for(int i=0; i<k - 1; i++){
            newTail = newTail->next;
        }
        
        Node* newHead = newTail->next;
        newTail->next = NULL;
        curr->next = head;
        
        
        return newHead;
    }
};