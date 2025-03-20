//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
    if (n < 2) return 0;

    vector<int> left(n, 0), right(n, 0);
    
    // Compute left max profit (First transaction)
    int min_price = prices[0];
    for (int i = 1; i < n; i++) {
        min_price = min(min_price, prices[i]);
        left[i] = max(left[i - 1], prices[i] - min_price);
    }

    // Compute right max profit (Second transaction)
    int max_price = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        max_price = max(max_price, prices[i]);
        right[i] = max(right[i + 1], max_price - prices[i]);
    }

    // Find maximum sum of left[i] + right[i]
    int max_profit = 0;
    for (int i = 0; i < n; i++) {
        max_profit = max(max_profit, left[i] + right[i]);
    }

    return max_profit;
}

int main() {
    vector<int> prices1 = {10, 22, 5, 75, 65, 80};
    cout << maxProfit(prices1) << endl;  // Output: 87

    vector<int> prices2 = {2, 30, 15, 10, 8, 25, 80};
    cout << maxProfit(prices2) << endl;  // Output: 100

    return 0;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends