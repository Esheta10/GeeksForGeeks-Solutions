/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(head == NULL || head->next == NULL)
            return head;
            
        // dummy heads
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        // Tail pointers to append at the end of each bucket
        Node* zeroTail = zeroHead;
        Node* oneTail = oneHead;
        Node* twoTail = twoHead;
        
        
        // Walk the original list and route each node
        Node* curr = head;
        while(curr != NULL){
            if(curr->data == 0){
                zeroTail->next = curr;
                zeroTail = zeroTail->next;
            } else if(curr->data == 1){
                oneTail->next = curr;
                oneTail = oneTail->next;
            } else {
                twoTail->next = curr;
                twoTail = twoTail->next;
            }
            
            curr = curr->next;
        }
        
        zeroTail->next = (oneHead->next != NULL) ? oneHead->next : twoHead->next;
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        
        Node* sortedHead = zeroHead->next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return sortedHead;
        
        
    }
};