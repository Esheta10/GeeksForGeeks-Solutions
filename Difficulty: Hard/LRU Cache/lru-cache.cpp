//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
 struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, Node*> cache; // Map to store key-node mapping
    Node* head; // Dummy head of the doubly linked list
    Node* tail; // Dummy tail of the doubly linked list
    int capacity; // Capacity of the cache
    int size; // Current size of the cache

    // Add a node right after the head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Remove a node from the list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Move a node to the front (most recently used)
    void moveToFront(Node* node) {
        removeNode(node);
        addNode(node);
    }

    // Remove the least recently used node (node before the tail)
    Node* popTail() {
        Node* lru = tail->prev;
        removeNode(lru);
        return lru;
    }

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;
        size = 0;
        head = new Node(0, 0); // Dummy head
        tail = new Node(0, 0); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToFront(node); // Mark as most recently used
            return node->value;
        }
        return -1; // Key not found
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key already exists, update its value and move to front
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            // Key does not exist, insert a new node
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
            size++;

            if (size > capacity) {
                // Remove the least recently used node
                Node* lru = popTail();
                cache.erase(lru->key);
                delete lru;
                size--;
            }
        }
    }

    // Destructor to clean up memory
    ~LRUCache() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends