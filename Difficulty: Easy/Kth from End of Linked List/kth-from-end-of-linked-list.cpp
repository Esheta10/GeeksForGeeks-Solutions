//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int lengthOfLinkedList(Node* head)
    {
        int l=0;
        while(head)
        {
            l++;
            head=head->next;
        }
        return l;
    }
    int getKthFromLast(Node *head, int k) {
        // Your code here
        int length = lengthOfLinkedList(head);
        
        
        // Handle invalid inputs
        if (k <= 0 || k > length) {
            return -1; // Return an error value, or handle appropriately
        }
        
        if(length==k)
        {
            Node* temp = head->next;
            //delete(head);
            return head->data;
        }
        Node* temp = head;
        Node* prev = NULL;
        
        int travel = length - k;
        while(travel--)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
       // delete(temp);
        return temp->data;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int x;
        cin >> x;
        cin.ignore();

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        Solution ob;
        cout << ob.getKthFromLast(head, x) << endl;
    }
    return 0;
}
// } Driver Code Ends