class myQueue {
  private:
    int capacity;
    int *arr;
    int front;
    int rear;
    int currSize;
  public:
    myQueue(int n) {
        // Define Data Structures
        capacity = n;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        currSize = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return currSize == 0;
    }

    bool isFull() {
        // check if the queue is full
        return currSize == capacity;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull())
            return;
            
        if(isEmpty())
            front = 0;
            
        arr[++rear] = x;
        currSize++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty())
            return;
            
        int val = arr[front];
        if(front == rear){
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        currSize--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty())
            return -1;
        return arr[front];
    }

    int getRear() {
        // Return the last element of queue
         if(isEmpty())
            return -1;
        return arr[rear];
    }
};