//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x)
        : data(x)
        , next(NULL) {}
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void addressstore(vector<Node*>& arr, Node* head) {
    Node* temp = head;
    int i = 0;
    while (temp) {
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(const vector<Node*>& before, const vector<Node*>& after, int num, int k) {
    if (k > num)
        return true;

    for (int i = 0; i < num; i++) {
        if ((i == k - 1) || (i == num - k)) {
            if (!((before[k - 1] == after[num - k]) &&
                  (before[num - k] == after[k - 1]))) {
                return false;
            }
        } else {
            if (before[i] != after[i]) {
                return false;
            }
        }
    }
    return true;
}


// } Driver Code Ends
// User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
}
*/

// Function to swap Kth node from beginning and end in a linked list.
class Solution {
  public:
    Node* swapKthNode(Node* head, int k) {
        // code here
        if (!head) return NULL; // Empty list
        
        Node *p1 = NULL, *p2 = NULL, *prev1 = NULL, *prev2 = NULL;
        Node *temp = head;
        int n = 0;

        // Calculate the length of the list
        while (temp) {
            n++;
            temp = temp->next;
        }
        
        if (k > n) return head; // k is out of bounds
        if (2 * k - 1 == n) return head; // Swapping the same node, no change needed

        temp = head;
        int idx = 1;

        // Traverse to find the k-th node from the start and end
        while (temp) {
            if (idx == k - 1) prev1 = temp;
            if (idx == k) p1 = temp;
            if (idx == n - k) prev2 = temp;
            if (idx == n - k + 1) p2 = temp;
            temp = temp->next;
            idx++;
        }

        // Swap the nodes by adjusting pointers
        if (prev1) prev1->next = p2;
        if (prev2) prev2->next = p1;

        Node* tempNode = p1->next;
        p1->next = p2->next;
        p2->next = tempNode;

        // Update head if needed
        if (k == 1) head = p2;
        if (k == n) head = p1;

        return head;
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

        int k;
        cin >> k;
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

        int num = arr.size();
        vector<Node*> before(num);
        addressstore(before, head);

        Solution ob;
        head = ob.swapKthNode(head, k);

        vector<Node*> after(num);
        addressstore(after, head);

        if (check(before, after, num, k))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}
// } Driver Code Ends