//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here
      
         vector<int> dp(n, 1);  // Initialize dp array with 1

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(a[i] - a[j]) == 1) {  // Check absolute difference
                dp[i] = max(dp[i], dp[j] + 1);  // Update dp[i]
            }
        }
    }
    
    // Find the maximum value in dp array
    int max_len = 1;
    for (int i = 0; i < n; i++) {
        max_len = max(max_len, dp[i]);
    }
    return max_len;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends