/*

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

class Solution {
  public:
    int addHelper(Node* node){
        
        if(node == NULL)
            return 1;
            
        
        int carry = addHelper(node->next);
        
        int sum = node->data + carry;
        node->data = sum % 10;
        return sum / 10;
    }
    Node* addOne(Node* head) {
        // Your Code here
        
        int carry = addHelper(head);
        // return head of list after adding one
        
        if(carry){
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};