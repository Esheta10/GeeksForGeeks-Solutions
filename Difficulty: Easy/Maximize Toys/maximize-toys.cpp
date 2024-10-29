//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
    // Step 1: Sort the array of toy costs
    sort(arr.begin(), arr.end());

    // Step 2: Calculate the maximum number of toys
    int count = 0;
    int totalCost = 0;
    
    for (int i = 0; i < N; i++) {
        if (totalCost + arr[i] <= K) {
            totalCost += arr[i];
            count++;
        } else {
            // If we exceed the budget, stop the purchase
            break;
        }
    }
    
    return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.toyCount(N, K, arr)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends