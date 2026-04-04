/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        if(head == NULL || head->next == NULL)
            return NULL;
            
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                break;
        }
        if(slow != fast)
            return NULL;
            
        Node* temp = slow->next;
        int count = 1;
        while(temp != slow){
            count++;
            temp = temp->next;
        }
        return count;
    }
};