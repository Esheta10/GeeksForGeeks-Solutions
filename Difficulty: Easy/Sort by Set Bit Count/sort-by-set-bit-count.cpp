//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        // Create a vector of pairs (number, original index)
    vector<pair<int, int>> arrWithIndex;
    for (int i = 0; i < n; i++) {
        arrWithIndex.push_back({arr[i], i});
    }

    // Sort using stable_sort to preserve original order for equal set bit counts
    stable_sort(arrWithIndex.begin(), arrWithIndex.end(),
                [](const pair<int, int>& a, const pair<int, int>& b) {
                    int countA = __builtin_popcount(a.first);
                    int countB = __builtin_popcount(b.first);

                    // Sort in descending order of set bits
                    if (countA != countB) {
                        return countA > countB;
                    }

                    // Stability is naturally handled by stable_sort
                    return false; // Keeps original order intact
                });

    // Copy sorted numbers back into the array
    for (int i = 0; i < n; i++) {
        arr[i] = arrWithIndex[i].first;
    }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends