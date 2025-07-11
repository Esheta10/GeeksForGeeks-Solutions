//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class MyStack {
  private:
    int arr[1000];
    int top;

  public:
    MyStack() { top = -1; }

    int pop();
    void push(int);
};


// } Driver Code Ends
// Function to push an integer into the stack.

/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack ::push(int x) {
    // Your Code
   if (top >= 999) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;  // Increment top and add the element
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    // Your Code
     if (top < 0) return -1;  // If stack is empty, return -1
        return arr[top--];       // Return the top element and decrement top
}


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Flush the newline character left by cin
    while (T--) {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int QueryType = nums[i++];
            if (QueryType == 1) {
                int a = nums[i++];
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << "\n~\n";
        delete sq;
    }
    return 0;
}

// } Driver Code Ends