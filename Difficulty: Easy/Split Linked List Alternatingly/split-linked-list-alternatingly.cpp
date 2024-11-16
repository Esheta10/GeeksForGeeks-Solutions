//{ Driver Code Starts
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


// } Driver Code Ends
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
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        if(head==NULL)
            return {NULL,NULL};
        
        Node* list1 = NULL;
        Node* list2 = NULL;
        
        Node** list1_ref = &list1;
        Node** list2_ref = &list2;
        
        Node* curr=head;
        int index=0;// To determine whether to add to list1 or list2
        
        while(curr)
        {
            if(index%2==0)
            {
                *list1_ref=curr;
                list1_ref = &((*list1_ref)->next);
            }
            else
            {
                *list2_ref = curr;
                list2_ref = &((*list2_ref)->next);
            }
            curr=curr->next;
            index++;
        }
         *list1_ref=NULL;
         *list2_ref=NULL;
         
         return {list1,list2};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

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

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends