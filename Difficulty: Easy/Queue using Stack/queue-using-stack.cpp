class myQueue {
  private:
    stack<int> inbox;
    stack<int> outbox;
    
    void transfer(){
        
        if(outbox.empty()){
            while(!inbox.empty()){
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
    }
  public:
    myQueue() {
        // Initialize your data members
    }

    void enqueue(int x) {
        // Implement enqueue operation
        inbox.push(x);
        
    }

    void dequeue() {
        // Implement dequeue operation
        if(isEmpty())
            return;
        transfer();
        // int val = outbox.top();
        outbox.pop();
        // return val;
    }

    int front() {
        // Implement front operation
        if(isEmpty())
            return -1;
        transfer();
        return outbox.top();
    }

    int size() {
        // Implement size operation
        return inbox.size() +  outbox.size();
    }
    bool isEmpty(){
        
        return inbox.empty() && outbox.empty();
    }
};
