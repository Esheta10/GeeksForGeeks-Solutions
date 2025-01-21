//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if (!head || k <= 1) return head;

    // Function to reverse a portion of the linked list
    auto reverseList = [](Node* start, Node* end) {
        Node* prev = nullptr;
        Node* curr = start;
        while (curr != end) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev; // New head of the reversed list
    };

    // Dummy node to simplify pointer handling
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prevGroupEnd = dummy;

    while (true) {
        // Find the start and end of the current group
        Node* groupStart = prevGroupEnd->next;
        Node* groupEnd = prevGroupEnd;
        for (int i = 0; i < k && groupEnd; ++i) {
            groupEnd = groupEnd->next;
        }

        // If there aren't enough nodes for a full group, stop
        if (!groupEnd) break;

        // Reverse the current group
        Node* nextGroupStart = groupEnd->next;
        groupEnd->next = nullptr; // Temporarily break the chain
        prevGroupEnd->next = reverseList(groupStart, nullptr);
        groupStart->next = nextGroupStart;

        // Move prevGroupEnd to the end of the reversed group
        prevGroupEnd = groupStart;
    }

    // Handle the remaining nodes (if any)
    Node* remainingStart = prevGroupEnd->next;
    if (remainingStart) {
        prevGroupEnd->next = reverseList(remainingStart, nullptr);
    }

    // Return the new head
    Node* newHead = dummy->next;
    delete dummy;
    return newHead;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends