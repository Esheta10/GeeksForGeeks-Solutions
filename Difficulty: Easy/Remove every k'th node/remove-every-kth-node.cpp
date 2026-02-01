/* Link list Node

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */
class Solution {
  public:
    Node* deleteK(Node* head, int k) {
        // code here
        //1. empty list
        if(head==NULL)
            return head;
        //2. delete head
        if(k==1){
            Node* newHead = head->next;
            delete head;
            return newHead;
        }
        //3. Delete every kth node
        int position = 1;
        Node* current = head;
        Node* previous = NULL;
        
        while(current != NULL){
            if(position % k ==0){
                // delete
                previous->next = current->next;
                delete current;
                current = previous->next;
            } else {
                // keep
                previous = current;
                current = current->next;
            }
            position++;
        }
        
        return head;
    }
};