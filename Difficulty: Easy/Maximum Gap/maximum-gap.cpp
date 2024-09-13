//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int maxSortedAdjacentDiff(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int result=0;
        int n=arr.size();
       
        for(int i=0;i<n-1;i++)
        {
                result=max(result,arr[i+1]-arr[i]);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxSortedAdjacentDiff(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends