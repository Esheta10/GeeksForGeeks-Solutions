/*Link list node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* getMiddle(struct Node* head){
        
        struct Node* slow = head;
        struct Node* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    Node* merge(struct Node* l1, struct Node* l2){
        
        if(l1 == NULL)
            return l2;
            
        if(l2 == NULL)
            return l1;
            
        struct Node* result;
        if(l1->data < l2->data){
            
            result = l1;
            result->next = merge(l1->next, l2);
        } else {
            
            result = l2;
            result->next = merge(l1,l2->next);
        }
        return result;
    }
    Node* insertionSort(struct Node* head_ref) {
        // code here
        if(head_ref == NULL || head_ref->next == NULL)
            return head_ref;
            
        struct Node* mid = getMiddle(head_ref);
        struct Node* rightHalf = mid->next;
        mid->next = NULL;
        
        struct Node* left = insertionSort(head_ref);
        struct Node* right = insertionSort(rightHalf);
        
        return merge(left, right);
    }
};