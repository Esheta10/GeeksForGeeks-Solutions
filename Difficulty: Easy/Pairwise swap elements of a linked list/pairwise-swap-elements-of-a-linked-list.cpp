//{ Driver Code Starts


#include <bits/stdc++.h>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* next;

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
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
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
    Node* pairWiseSwap(Node* head) {
        // The task is to complete this method
         // If the list is empty or has only one node, no swapping needed
    if(head==NULL || head->next==NULL)
        return head;
        
    Node* temp = head->next;
    head->next=pairWiseSwap(head->next->next);
    temp->next=head;
    
    return temp;
    
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t input

    while (t--) {
        vector<int> arr;
        string input;

        // Read the array of linked list elements
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl; // handle empty input
            continue;
        }

        // Create linked list from the input array
        Node* head = new Node(arr[0]);
        Node* tail = head;
        map<Node*, int> mp;
        mp[head] = head->data;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
            mp[tail] = tail->data;
        }

        Node* failure = new Node(-1);
        Solution ob;
        head = ob.pairWiseSwap(head);
        int flag = 0;
        Node* temp = head;
        while (temp) {
            if (mp[temp] != temp->data) {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag)
            printList(failure);
        else
            printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends