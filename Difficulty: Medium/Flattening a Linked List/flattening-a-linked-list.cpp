/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *mergeTwoLists(Node *l1, Node *l2){
        
        if(l1 == NULL)
            return l2;
        
        if(l2 == NULL)
            return l1;
            
        
        Node *result;
        if(l1->data < l2->data){
            
            result = l1;
            result->bottom = mergeTwoLists(l1->bottom, l2);
        } else {
            
            result = l2;
            result->bottom = mergeTwoLists(l1, l2->bottom);
        }
        
        return result;
    }
    Node *flatten(Node *root) {
        // code here
        if(root == NULL)
            return NULL;
            
        Node *head2 = flatten(root->next);
        
        return mergeTwoLists(root, head2);
    }
};