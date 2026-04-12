/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {
  private:
    Node* head;
  public:
    myStack() {
        // Initialize your data members
        head = NULL;
    }

    bool isEmpty() {
        // check if the stack is empty
        return head == NULL;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        // Removes the top element of the stack
        int val = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(isEmpty())
            return -1;
            
        return head->data;
    }

    int size() {
        // Returns the current size of the stack.
        Node* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
};