class myDeque {
  private:
   vector<int> deq;
   int front, rear, size, capacity;
  public:
    myDeque(int n) {
        // Initialize your data members
        front = -1;
        rear = -1;
        size = 0;
        capacity = n ;
        deq = vector<int>(capacity);
    }
    bool isFull(){
        return (rear + 1) % capacity == front;
    }
    bool isEmpty(){
        return front == -1;
    }
    void insertFront(int x) {
        // Insert element at the front
        if(isFull())
            return;
        
        if(isEmpty()){
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        deq[front] = x;
        size++;
    }

    void insertRear(int x) {
        // Insert element at the rear
        if(isFull())
            return;
        if(isEmpty()){
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        deq[rear] = x;
        size++;
    }

    int deleteFront() {
        // Delete element from the front
        if(isEmpty())
            return -1;
        
        int val = deq[front];
        if(front == rear)
            front = rear = -1;
        else {
            front = (front + 1) % capacity;
        }
        size--;
        return val;
    }

    int deleteRear() {
        // Delete element from the rear
        if(isEmpty())
            return -1;
        int val = deq[rear];
        if(front == rear){
            front = rear = -1;
        } else {
            rear = (rear -1 + capacity) % capacity;
        }
        size--;
        return val;
    }

    int frontEle() {
        // Get the front element
        return isEmpty() ? -1 : deq[front];
    }

    int rearEle() {
        // Get the rear element
        return isEmpty() ? -1 : deq[rear];
    }
};