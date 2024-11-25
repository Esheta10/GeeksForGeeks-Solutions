//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        if(arr.empty())
            return 0;
            
        int max_prod=arr[0];
        int min_prod=arr[0];
        int result=arr[0];
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]<0)
                swap(max_prod,min_prod);
                
            max_prod = max(arr[i],arr[i]*max_prod);
            min_prod = min(arr[i],arr[i]*min_prod);
            
            result = max(result,max_prod);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends