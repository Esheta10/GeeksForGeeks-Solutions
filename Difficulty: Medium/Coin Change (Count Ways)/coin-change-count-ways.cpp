//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long int count(vector<int> coins, int sum) {
        // code here.
       // Create a dp array initialized to 0 with size sum+1
    vector<long long int> dp(sum + 1, 0);
    
    // There's 1 way to make a sum of 0, by choosing no coins.
    dp[0] = 1;

    // Loop through each coin
    for (int coin : coins) {
        // Update the dp array for all sums >= coin
        for (int j = coin; j <= sum; ++j) {
            dp[j] += dp[j - coin]; // Update dp[j] based on dp[j - coin]
        }
    }

    return dp[sum]; // Return the number of ways to form the given sum
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
    }

    return 0;
}

// } Driver Code Ends