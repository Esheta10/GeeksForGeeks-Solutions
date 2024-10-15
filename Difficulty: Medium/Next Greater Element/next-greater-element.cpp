//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> result(n, -1);  // Initialize the result array with -1
    stack<long long> s;  // Stack to keep track of next greater elements
    
    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack that are less than or equal to arr[i]
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        
        // If the stack is not empty, the top is the next greater element
        if (!s.empty()) {
            result[i] = s.top();
        }
        
        // Push the current element onto the stack
        s.push(arr[i]);
    }
    
    return result;  // Return the vector containing next greater elements
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends