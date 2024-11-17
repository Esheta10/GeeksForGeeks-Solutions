//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
  public:
    Node* reverseBetween(int a, int b, Node* head) {
        // code here
        if(head==NULL || head->next==NULL)
            return head;
            
        Node* dummy = new Node(0);
        dummy->next=head;
        
        Node* prev = dummy;
        for(int i=1;i<a;i++)
        {
            prev=prev->next;
        }
        Node* curr = prev->next;
        
        for(int i=1;i<=b-a;i++)
        {
            Node *temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }
        return dummy->next;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
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

        int a = arr[0], b = arr[1];

        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        if (arr2.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr2[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr2.size(); ++i) {
            data = arr2[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node* newhead = ob.reverseBetween(a, b, head);
        printList(newhead);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends