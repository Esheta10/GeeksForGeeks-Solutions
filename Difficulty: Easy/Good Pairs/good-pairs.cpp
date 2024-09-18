//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long long solve(int arr[], int n){
    // your code here
       unordered_map<int,int> freq;
      
       for(int i=0;i<n;i++)
            freq[arr[i]]++;
            
       long long countPairs = 0;
        
        // Step 2: Count pairs for distinct elements
        for (auto it1 = freq.begin(); it1 != freq.end(); ++it1) {
            for (auto it2 = next(it1); it2 != freq.end(); ++it2) {
                // Multiplying the frequency of two distinct elements
                countPairs += it1->second * it2->second;
            }
        }

        return countPairs;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int arr[n];
        for(int i = 0; i<n; i++)
            cin >> arr[i];
        Solution ob;
        long long ans = ob.solve(arr,n);
        cout << ans << endl;
    }
}

// } Driver Code Ends