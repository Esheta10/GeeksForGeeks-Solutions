//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
     // Create a new node for x
    Node* newNode = new Node();
    newNode->data = x;
    newNode->prev = newNode->next = nullptr;
    
    // If the list is empty, newNode becomes the head
    if (!head) return newNode;
    
    // If x should be inserted before the head node
    if (x <= head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode; // newNode is the new head
    }
    
    // Traverse the list to find the correct position for x
    Node* curr = head;
    while (curr->next && curr->next->data < x) {
        curr = curr->next;
    }
    
    // Insert newNode after curr
    newNode->next = curr->next;
    newNode->prev = curr;
    
    if (curr->next) { // if not inserting at the end
        curr->next->prev = newNode;
    }
    curr->next = newNode;
    
    return head; // return the head of the modified list
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }

        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends