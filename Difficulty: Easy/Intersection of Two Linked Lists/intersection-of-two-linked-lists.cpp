//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
    
    Node* findIntersection(Node* head1, Node* head2) {
        // code here
        // Create a hash set to store the values of head2
        std::unordered_set<int> valuesSet;
        Node* temp = head2;
        while (temp != nullptr) {
            valuesSet.insert(temp->data);
            temp = temp->next;
        }

        // Create a dummy node for the result list
        Node* dummy = new Node(-1);
        Node* result = dummy;

        // Traverse head1 and find common elements
        temp = head1;
        while (temp != nullptr) {
            if (valuesSet.find(temp->data) != valuesSet.end()) {
                // Add to the result list
                result->next = new Node(temp->data);
                result = result->next;

                // Remove the value from the set to avoid duplicates
                valuesSet.erase(temp->data);
            }
            temp = temp->next;
        }

        // Return the head of the result list
        return dummy->next;
    }
};

//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        int tmp;
        string input1, input2;

        getline(cin, input1);
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node* new_node = new Node(tmp);
            if (!head1) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2);
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node* new_node = new Node(tmp);
            if (!head2) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node* result = obj.findIntersection(head1, head2);
        printList(result);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends