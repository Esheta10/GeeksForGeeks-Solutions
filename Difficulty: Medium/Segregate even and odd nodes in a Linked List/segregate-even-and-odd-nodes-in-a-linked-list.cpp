//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

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
    Node* divide(Node* head) {
        // code here
       // Base case: If the list is empty or has only one element
        if (head == NULL || head->next == NULL)
            return head;

        Node* evenHead = NULL; // Start of even list
        Node* oddHead = NULL;  // Start of odd list
        Node* evenTail = NULL; // Tail of even list
        Node* oddTail = NULL;  // Tail of odd list

        Node* current = head;
        while (current != NULL) {
            if (current->data % 2 == 0) { // Even node
                if (evenHead == NULL) {
                    evenHead = current; // Set head of even list
                    evenTail = evenHead; // Set tail of even list
                } else {
                    evenTail->next = current; // Append to even list
                    evenTail = evenTail->next;
                }
            } else { // Odd node
                if (oddHead == NULL) {
                    oddHead = current; // Set head of odd list
                    oddTail = oddHead; // Set tail of odd list
                } else {
                    oddTail->next = current; // Append to odd list
                    oddTail = oddTail->next;
                }
            }
            current = current->next;
        }

        // End of odd list should point to NULL
        if (oddTail != NULL) {
            oddTail->next = NULL;
        }

        // If no even nodes, return odd list
        if (evenHead == NULL)
            return oddHead;

        // Connect the even list to the odd list
        evenTail->next = oddHead;
        
        // Return the head of the even list
        return evenHead;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty())
            continue;

        int data = arr[0];
        int N = arr.size();
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < N; ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(head);
        printList(ans);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends