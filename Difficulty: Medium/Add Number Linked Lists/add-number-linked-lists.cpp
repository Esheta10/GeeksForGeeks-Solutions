//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
void removeZero(Node* &head){
    Node* next = NULL;
    while(head != NULL && head -> data == 0){
        next = head -> next;
        head -> next = NULL;
        delete head;
        head = next;
    }
    
}

void reverse(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    
    head = prev;
}

void insertAtHead(Node* &head, int d){
    
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        return;
    }
    
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
    
    return;
    
}

class Solution {
  public:
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* num1, Node* num2) {
        Node* head = NULL;
        
        removeZero(num1);
        removeZero(num2);
        
        reverse(num1);
        reverse(num2);
        
        int carry = 0;
        int value;
        int ans;
        while(num1 != NULL && num2 != NULL){
            
                value = (num1 -> data) + (num2 -> data) + (carry);
                carry = value/10;
                ans = value%10;
                insertAtHead(head, ans);
                
                num1 = num1 -> next;
                num2 = num2 -> next;
                
        }
        
        while(num1 != NULL){
            value = (num1 -> data) + carry;
            carry = value/10;
            ans = value%10;
            insertAtHead(head, ans);
            num1 = num1 -> next;
        }
        
        while(num2 != NULL){
            value = (num2 -> data) + carry;
            carry = value/10;
            ans = value%10;
            insertAtHead(head, ans);
            num2 = num2 -> next;
        }
        
        if(carry == 1){
            insertAtHead(head, 1);
        }

        
        return head;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends