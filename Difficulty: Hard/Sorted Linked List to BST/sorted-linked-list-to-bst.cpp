//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct LNode {
    int data;
    struct LNode* next;

    LNode(int x) {
        data = x;
        next = NULL;
    }
};

struct TNode {
    int data;
    struct TNode* left;
    struct TNode* right;

    TNode(int x) {
        data = x;
        left = right = NULL;
    }
};

void preOrder(TNode* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}


// } Driver Code Ends
/*
struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; */
class Solution {
  public:
    TNode *sortedListToBST(LNode *head) {
        // code here
        if(head==NULL)
            return NULL;
        
        if(head->next==NULL)
            return new TNode(head->data);
        
        LNode *slow=head;
        LNode *fast=head;
        LNode *slow_prev=NULL;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow_prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        TNode *root = new TNode(slow->data);
        slow_prev->next=NULL;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        return root;
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
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        LNode* head = new LNode(data);
        LNode* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new LNode(data);
            tail = tail->next;
        }

        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends